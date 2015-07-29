#include <iostream>

using namespace std;

int ans;

void rec(int n)
{
	ans++;
	for (int i = n - 1; i >= 0; i--)
		rec(i);
}

int main()
{
	int n;

	cin >> n;

	rec(n);

	cout << ans;

	return 0;
}
