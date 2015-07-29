#include "Solution.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstring>
#include <time.h>

using namespace std;

char buff[1024];
int otherFactoryNum = 0;
int factories[7] = {};

std::map<int, int> Strategy() {
	std::map<int, int> answer;
	int k = 0;
	for (int i = 0; i < MAX_FACTORY_COUNT; i++) {
		const Factory &f = pWorld->factories[i];
		if (f.id < 0) continue; //пропускаем "мёртвые" заводы
		if (f.owner != playerIndex) continue; //пропускаем чужие заводы
		answer[f.id] = 0; //говорим, что на нашем заводе надо строить!
	}
	return answer;
}

void goToRandomFactory(char buff[]) {
	int num = 0;
	num = rand() % 7;
	const Factory &f = pWorld->factories[num];

	double delta = rand() % 50;
	delta -= 25;

	//пишем инициализирующий скрипт: бежать в центр этого завода
	sprintf(buff, "gofact = {x = %lf, y = %lf}", f.position.x + delta, f.position.y + delta);
}

double get_dist(double x, double y) {
	return sqrt(x * x + y * y);
}

void goToClosestFactory(char buff[], int robotIndex) {
	if (otherFactoryNum == 0) {
		goToRandomFactory(buff);
	}
	else {
		//int num = rand() % otherFactoryNum;
		double dist = 10000;
		int bi = 0;

		double cx = 0, cy = 0;
		const Robot &r = pWorld -> robots[robotIndex];
		cx = r.position.x;
		cy = r.position.y;

		for (int i = 0; i < otherFactoryNum; i++) {
			double ox = 0, oy = 0;
			const Factory &of = pWorld->factories[factories[i]];
			ox = of.position.x;
			oy = of.position.y;
			if (get_dist(cx - ox, cy - oy) < dist) {
				dist = get_dist(cx - ox, cy - oy);
				bi = i;
			}
		}

		double delta = rand() % 70;
		delta -= 35;

		const Factory &f = pWorld->factories[factories[bi]];

		//пишем инициализирующий скрипт: бежать в центр этого завода
		sprintf(buff, "gofact = {x = %lf, y = %lf}", f.position.x + delta, f.position.y + delta);
	}
}


void goToNotOwnFactory(char buff[]) {
	if (otherFactoryNum == 0) {
		goToRandomFactory(buff);
	}
	else {
		int num = rand() % otherFactoryNum;
		const Factory &f = pWorld->factories[factories[num]];

		double delta = rand() % 70;
		delta -= 35;

		sprintf(buff, "gofact = {x = %lf, y = %lf}", f.position.x + delta, f.position.y + delta);
	}
}

void goToFactory(char buff[], int x) {
	const Factory &f = pWorld->factories[factories[x]];
	double delta = rand() % 70;
	delta -= 35;
	sprintf(buff, "gofact = {x = %lf, y = %lf}", f.position.x + delta, f.position.y + delta);
}

void captureFactory(int robotIndex) {
	if (rand() % 10 < 5)
		goToClosestFactory(buff, robotIndex);
	else
		goToNotOwnFactory(buff);
}

void beKiller() {
	sprintf(buff, "isKiller = true\n");
}

void bePatrol(int robotIndex) {
	double rat = 0.1 * (robotIndex % 5);
        //пишем в строку инициализирующий скрипт на LUA (задаём путь для патруля)
        sprintf(buff, "path = {}\n \
                       path[0] = {x = %lf, y = %lf}\n \
                       path[1] = {x = %lf, y = %lf}\n \
                       path[2] = {x = %lf, y = %lf}\n \
                       path[3] = {x = %lf, y = %lf}\n", 
                       FIELD_SIZE*rat, FIELD_SIZE*rat, 
                       FIELD_SIZE*(1-rat), FIELD_SIZE*rat, 
                       FIELD_SIZE*(1-rat), FIELD_SIZE*(1-rat), 
                       FIELD_SIZE*rat, FIELD_SIZE*(1-rat));
}

std::pair<std::string, std::string> Program(int robotIndex) {
	srand(time(NULL));

	otherFactoryNum = 0;
	
	for (int i = 0; i < MAX_FACTORY_COUNT; i++) {
		const Factory &f = pWorld->factories[i];
		if (f.id < 0) continue; //пропускаем "мёртвые" заводы
		if (f.owner == playerIndex) continue; //пропускаем свои заводы
		factories[otherFactoryNum] = i;
		otherFactoryNum++;
	}

	if (robotIndex < 40)
		goToFactory(buff, robotIndex % 7);
	else if (otherFactoryNum == 0) {
		if (rand() & 1)
			bePatrol(robotIndex);
		else
			beKiller();
	}
	else {
		captureFactory(robotIndex);
	}

	return make_pair("", std::string(buff));
}
