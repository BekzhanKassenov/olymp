#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r", stdin);
	#endif
	double n;
	vector <double> a;
	while (cin >> n)
		a.push_back(n);
	vector <double> :: iterator it;
	reverse(a.begin(), a.end());
	for (it = a.begin(); it != a.end(); it++)
		{
			printf("%.9lf\n", sqrt(*it));
		}
	return 0;
}
