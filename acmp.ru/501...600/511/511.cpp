#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	int cnt = (n - 1) * 5;

	int h = cnt / 60;
	int m = cnt % 60;

	if (h > 12)
		{
			cout << "NO";

			return 0;
		}

	if (h == 12)
		{
			if (m > 0)
				cout << "NO";
			else
				cout << h << ' ' << m;	
		}
	else
		cout << h << ' ' << m;

	return 0;	
}
