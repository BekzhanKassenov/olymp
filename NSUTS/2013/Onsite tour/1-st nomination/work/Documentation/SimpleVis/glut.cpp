#include "GameLogic\World.h"
#include "Common\InterProcess.h"
#include "Common\History.h"
#include "Common\Utils.h"
#include "Common\Timing.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include "glut.h"

//the maximal possible FPS (usually limited by vsync)
const double MAX_FRAMES_PER_SEC = 50.0;
//the maximal number of cycles modelled per sec
const double MAX_CYCLES_PER_SEC = 300.0;


const char *APP_NAME = "AI War";
inline double getTime() { return GetTime() * 1000; }

int width, height;

bool inmainloop = false;
double lastframe;

double WorldToGL(double len) { return len * 2.0 / FIELD_SIZE; };
Point WorldToGL(Point w) { return (w / FIELD_SIZE)*2.0 - Point(1.0, 1.0); };
Point ScreenToWorld(int x, int y) {
	Point pos(double(x)/width, 1.0 - double(y)/height);
	return pos * FIELD_SIZE;
};


bool HistoryMode = false;
int currentFrameIdx = 0;
const WorldData *GetWorldData() {
    return HistoryMode ? HistoryReader::Get().GetFrame(currentFrameIdx) : World::Get().GetData();
}
bool Iterate() {
    if (!HistoryMode) {
        bool gameover = World::Get().DoCycle();
        HistoryWriter::Get().WriteFrame(World::Get().GetData());
        return gameover;
    }
    else {
        currentFrameIdx++;
        return currentFrameIdx >= HistoryReader::Get().GetLength();
    }
};

std::vector<std::string> arguments;
void Init() {
    if (!HistoryMode) {
        SetLogFileName("ServerLog.txt");
        HistoryWriter::Get().Init("History.bin");
        HistoryWriter::Get().WriteFrame(World::Get().GetData());
        for (size_t i = 0; i < arguments.size(); i++)
            ServerInterProcess::Get().LaunchClientProcess(i, arguments[i].c_str());
    }
    else {
        bool ok = HistoryReader::Get().Init(arguments[0].c_str());
        if (!ok) {
            fprintf(stderr, "Cannot find history file\n");
            exit(390);
        }
    }
}
void Exit() {
    if (!HistoryMode)
        ServerInterProcess::Get().Terminate(true);
    else
        exit(0);
};

int BACKCOLOR = 0;
static void display(void) {
	if (BACKCOLOR) glClearColor(0.0, 0.0, 0.0, 0.0);
	else glClearColor(0.1, 0.1, 0.1, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	for (int i = 0; i<MAX_UNITS_COUNT; i++) {
        int type = SlotToType(i);
        int idx = SlotToIndex(i);
        const Unit *ent = 0;
        if (type == 1) ent = &GetWorldData()->factories[idx];
        if (type == 2) ent = &GetWorldData()->robots[idx];
        if (type == 3) ent = &GetWorldData()->projectiles[idx];
        assert(ent);
        if (ent->id < 0) continue;

        int owner = ent->owner;
		if (type == 3) {
            glColor3d(1.0, 0.1 + 0.4 * (owner == 0), 0.1 + 0.4 * (owner == 1));
        }
        else {
            double mainColor = (type == 1 ? 0.5 : 1.0);
            double otherColor = (type == 1 ? 0.2 : 0.2);
            double red = otherColor + (type == 1 ? 0.3 : 0.0);
            if (owner == -1) glColor3d(0.4, 0.4, 0.4);
		    if (owner == 0) glColor3d(red, mainColor, otherColor);
		    if (owner == 1) glColor3d(red, otherColor, mainColor);
        }

        Point pos = WorldToGL(ent->position);
        double rad = WorldToGL(ent->radius);

		glPointSize(2);
		glBegin(GL_POINTS);
			glVertex2dv(&pos.x);
		glEnd();

	    int verts = int(sqrt(rad * 10000.0));
        verts = std::max(verts, 10);
        verts = std::min(verts, 1000);
		glBegin(GL_POLYGON);
			for (int j = 0; j<=verts; j++) {
				double ang = 4.0*acos(0.0) * j/verts;
				Point v = pos + Point(cos(ang), sin(ang)) * rad;
				glVertex2dv(&v.x);
			}
		glEnd();
	}

	glutSwapBuffers();
}

static void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	::width = width;
	::height = height;
	glutPostRedisplay();
}

static void keyboardDown(unsigned char c, int x, int y) {
	if (c == 27) Exit();
	//uKeyDown(c);
}

static void keyboardUp(unsigned char c, int x, int y) {
	//uKeyUp(c);
}

/*static void motion(int x, int y) {
	mouseX = x;
	mouseY = y;
}

static void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) pressedmouse = (state == GLUT_DOWN);
}*/

static void idle(void) {
	if (!inmainloop) {
		Init();
		inmainloop = true;
		lastframe = getTime();
		return;
	}
	double newframe = getTime();
	double deltatime = (newframe - lastframe) * 0.001;
	if (deltatime < 1.0 / MAX_CYCLES_PER_SEC) return;

	//update fps
	static double lastfpscalc = getTime();
	static int thissecondcount = 0;
	static double fps = MAX_FRAMES_PER_SEC;
	if (newframe - lastfpscalc > 1000.0) {
		fps = thissecondcount / (newframe - lastfpscalc) * 1000.0;
		thissecondcount = 0;
		lastfpscalc = newframe;

 	    char buff[256];
        if (!HistoryMode) {
    	    //count living entities
            int tcnt[4] = {0, World::Get().GetUnitsCount(1), World::Get().GetUnitsCount(2), World::Get().GetUnitsCount(3)};
            sprintf(buff,
                "FPS = %0.2lf"
                "   Time = %d"
                "   Score = %d vs %d"
                "   Entities = %d (%d:%d:%d)"
                , fps, World::Get().GetData()->currentTime
                , World::Get().GetScore(0), World::Get().GetScore(1)
                , tcnt[1]+tcnt[2]+tcnt[3], tcnt[1], tcnt[2], tcnt[3]
            );
        }
        else {
            sprintf(buff,
                "FPS = %0.2lf"
                "   Time = %d"
                , fps, currentFrameIdx
            );
        }
    	glutSetWindowTitle(buff);
	}
	thissecondcount++;
	lastframe = newframe;

    bool gameover = Iterate();
    if (gameover)
        Exit();


    static double lastRedisplay = getTime();
    if (getTime() - lastRedisplay >= 1000.0 / MAX_FRAMES_PER_SEC) {
        glutPostRedisplay();
        lastRedisplay = getTime();
    }
}

int main(int argc, char **argv) {
    for (int i = 1; i<argc; i++) {
        if (strcmp(argv[i], "-d") == 0)
            EnableUnlimitedMode();
        else if (strcmp(argv[i], "-h") == 0)
            HistoryMode = true;
        else
            arguments.push_back(argv[i]);
    }
    if (!HistoryMode) {
        if (arguments.size() != 2) {
            fprintf(stderr, "Specify exactly two client programs as parameters\n");
            return 135;
        }
    }
    else {
        if (arguments.size() != 1) {
            fprintf(stderr, "Specify history file as parameter\n");
            return 135;
        }
    }

	//glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(700, 700);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow(APP_NAME);

	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	/*glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutPassiveMotionFunc(motion);*/

	glDisable(GL_DEPTH_TEST);

	glutMainLoop();
	return 0;
}
