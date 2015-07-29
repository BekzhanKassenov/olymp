#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int pra[4] = {8, 7, 9, 4}; 
int prb[4] = {2, 3, 1, 6};

const double sm = 1 / (sqrt(2));

double dx[10] = {0, -sm,  0,  sm, -1, 0, 1, -sm, 0, sm};
double dy[10] = {0, -sm, -1, -sm,  0, 0, 0,  sm, 1, sm};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	getline(cin, s);

	int a[10] = {0};

	double x = 0, y = 0;

	for (int i = 0; i < (int)s.size(); i++)
		{
			if (s[i] == '0')
				break;

			x += dx[s[i] - '0'];
			y += dy[s[i] - '0'];
		}

	/*for (int i = 0; i < 4; i++)
		{
			if (a[pra[i]] > a[prb[i]])
				{
					a[pra[i]] -= a[prb[i]];
					a[prb[i]] = 0;
				}
			else
				{
					a[prb[i]] -= a[pra[i]];
					a[pra[i]] = 0;
				}	
		}

	double x = 0, y = 0;

	for (int i = 0; i < 10; i++)
		{
			x += dx[i] * a[i];
			y += dy[i] * a[i];
		}*/	

	printf("%.10lf %.10lf", x, y);

	return 0;
}
