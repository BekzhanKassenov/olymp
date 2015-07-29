#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int> > g;

int n;

int deikstra(int v, int mx)
{
	priority_queue <pair <int, int> > q;

	vector <int> d(n, INF);
}