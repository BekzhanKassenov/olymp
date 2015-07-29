#include <iostream>
#include <cstdio>

using namespace std;

int main()
{           	
	int n, m;

	cin >> n >> m;

	int ans1 = min(n, m);

	int t;

	if (m > n)
		t = 1;
	else
		t = 2;

	int ans2 = max(n, m);

	for (int i = 0; i < ans1; i++)
		cout << "BG";

	if (t == 2)
		{
			for (int i = 0; i < ans2 - ans1; i++)
				{
					cout << 'B';
				}
		}
	else
		for (int i = 0; i < ans2 - ans1; i++)
			cout << 'G';
	return 0;
}
