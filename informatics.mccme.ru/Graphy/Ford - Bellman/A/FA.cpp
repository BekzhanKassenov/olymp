#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct edge
{
	int from, to, val;
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	vector <edge> a(m);

	for (int i = 0; i < m; i++)
		cin >> a[i].from >> a[i].to >> a[i].cost;


}
