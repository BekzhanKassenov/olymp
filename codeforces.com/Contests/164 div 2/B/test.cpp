#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	long long n;

	cin >> n;

	cout << (n * n * n + 5 * n) / 6;
}
