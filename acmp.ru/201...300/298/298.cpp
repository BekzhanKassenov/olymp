#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

#define MP make_pair
#define EPS 1e-5

int comp(double a, double b)
{
	if (fabs(a - b) < EPS)
		return 0;

	if (a - b > EPS)
		return 1;

	else
		return -1;	

}

bool operator != (pair <double, double> &a, pair <double, double> &b)
{
	if (comp (a.first, b.first) != 0)
		return false;
	
	if (comp(a.second, b.second) != 0)
		return false;

	return false;
}

int gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return a + b;

	if (a > b)
		return gcd(a % b, b);
	else
		return gcd(b % a, a);	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	if (n == 1)
		{
			cout << 1;
			return 0;
		}

	set <pair <int, int> > s;

	for (int i = 0; i < n; i++)
		{
		   int x, y;

			cin >> x >> y;

			if (x != 0 || y != 0)
				{
					int a = gcd(abs(x), abs(y));

					x /= a;
					y /= a;

					s.insert(MP(x, y));
				}
		}

	cout << s.size();	
}
