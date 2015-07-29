#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	double n, p;

	cin >> n >> p;

	double ans = (1 - (p / 100.0));

	ans /= n;

	ans += (p / 100.0);

	printf("%.10lf", 1 / ans);


	return 0;	
}
