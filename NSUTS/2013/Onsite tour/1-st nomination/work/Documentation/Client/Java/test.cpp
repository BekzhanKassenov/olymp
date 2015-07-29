#include "Client/SolutionAdapter.h"
#include <cstdio>
#include <iostream>

using namespace std;

WorldData world;
const WorldData *pWorld;

int playerIndex = 5;

int main() {
    printf("%d\n", sizeof(WorldData));
    pWorld = &world;
    world.projectiles[5].velocity.x = -55.17;
    world.currentTime = 768;
    map<int, int> m = Strategy();
    for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << "->" << it->second << endl;
    }
    pair<string, string> p = Program(15);
    cout << p.first << ", " << p.second << endl;


    return 0;
}
