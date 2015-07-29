#include <cstdlib>
#include <cstdio>
#include <cassert>

#include <windows.h>
#include <iostream>
#include <stdio.h> 
#include "Client\SolutionAdapter.h"



typedef void (__stdcall *SENDWORLD)(const WorldData *, int);
typedef void (__stdcall *PROGRAM)(int, char*&, int&, char*&, int&);
typedef void (__stdcall *STRATEGY)(int*);

bool init();
SENDWORLD testWorld;
SENDWORLD initWorld;
PROGRAM   program;
STRATEGY  strategy;

bool inited = false;
std::map<int, int> Strategy() {
	if (!inited)
		inited = init();
	assert(inited);
	int facts[MAX_FACTORY_COUNT];
	memset(facts, -1, MAX_FACTORY_COUNT*sizeof(int));
	strategy(facts);

	std::map<int, int> res;
	for (int i = 0; i < MAX_FACTORY_COUNT; ++i)
		if (facts[i] != -1)
			res[i] = facts[i];

	return res;
}

std::pair<std::string, std::string> Program(int robotIndex) {
	if (!inited)
		inited = init();
	assert(inited);
	char *prog = NULL, *data = NULL;
	int progLen = 0, dataLen = 0;
	program(robotIndex, data, dataLen, prog, progLen);
	std::string s1;
	if (data && dataLen) s1.assign(data, dataLen);
	std::string s2;
	if (prog && progLen) s2.assign(prog, progLen);
	return make_pair(s1, s2);
}


template<class T>
void assign(T& v, const HINSTANCE& h, const char* name) {
	v = (T)GetProcAddress(h, name);
	assert(v);
}

#define QUOTE(x) #x
#define TOSTR(x) QUOTE(x)

#ifndef PASCALDLL
#define PASCALDLL Api
#endif

bool init() {
  HINSTANCE hGetProcIDDLL = LoadLibrary(TOSTR(PASCALDLL) ".dll");

  if (hGetProcIDDLL == NULL) {
	  logprintf("Cannot locate the .dll file\n");
	  return false;
  } else {
	  logprintf("Loaded dll\n");
	  assign<SENDWORLD>(testWorld, hGetProcIDDLL, "TestWorld");
	  assign<SENDWORLD>(initWorld, hGetProcIDDLL, "InitWorld");
	  assign<PROGRAM>(program, hGetProcIDDLL, "SolutionProgram");
	  assign<STRATEGY>(strategy, hGetProcIDDLL, "SolutionStrategy");
  }

  WorldData * res = new WorldData;
  res->maximalMatchTime = 1234567;
  res->factoryClasses[0].radius = 1.1;
  res->factoryClasses[0].score = 1000000009;

  res->robotClasses[0].maxSpeed = 100.555;
  res->robotClasses[0].timeToBuild = 17239;

  res->projectileClasses[0].isHoming = 10;
  res->projectileClasses[0].speed = 777.777;

  res->factories[5].id = 7;
  res->factories[5].position.x = 0.5;
  res->factories[5].position.y = 123123;
  res->factories[5].captureProgressTime = 81;

  res->robots[100].id = 111112222;
  res->robots[100].position.x = 111111.5;
  res->robots[100].position.y = 17171;
  res->robots[100].shootTimeRemaining = 1919;

  res->projectiles[7].id = 111;
  res->projectiles[7].position.x = 87777;
  res->projectiles[7].position.y = 123.55;
  res->projectiles[7].homingTargetId = 1160;

  testWorld(res, playerIndex);
  delete res;
  initWorld(pWorld, playerIndex);
  return true;
}
