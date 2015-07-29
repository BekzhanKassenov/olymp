#include <iostream>
#include <cstdio>
#include <cmath>
#define sqr(x) (x)*(x)

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	double q;
	cin >> n >> q;
	double x, y, _y1, x1;
	for (int i = 0; i < n; i++)
		{
			cin >> x >> y >> x1 >> _y1;
			if (sqrt(sqr(x) + sqr(y)) * q < sqrt (sqr(x1) + (sqr(_y1))))
				{
					cout << "No";
					return 0;
				}
		}
	cout << "Yes";
	return 0;
}
