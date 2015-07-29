#include <iostream>

using namespace std;

int a[101];

int main()
{
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
		{
			cin >> x;
			a[x] ++;
		}
	for (int i = 0; i < 101; i++)
		for (;a[i]; a[i]--)
			cout << i << ' ';
	return 0;
}
