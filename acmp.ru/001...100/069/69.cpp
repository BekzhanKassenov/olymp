#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	double n, a;

	cin >> n >> a;

	double r = a / (2 * tan(pi / n));
	double R = a / (2 * sin(pi / n));

	if (R - r - 1 < 0)
		cout << "YES";
	else
		cout << "NO";	
}
