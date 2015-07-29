#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <list>

using namespace std;

list <int> as[1001];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	scanf("%d", &n);

	int a, b;

	string s;

	for (int i = 0; i < n; i++)
		{
		   cin >> s;

			if (s == "PUSH")
				{
					scanf("%d%d", &a, &b);

					as[a].push_back(b);
				}
			else
				{
					scanf("%d", &a);

					printf("%d\n", as[a].back());

					as[a].pop_back();
				}
		}
	return 0;
}
