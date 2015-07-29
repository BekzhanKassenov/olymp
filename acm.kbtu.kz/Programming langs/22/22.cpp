#include <iostream>

int a[10];

using namespace std;

int main()
{
	int x;
	while (cin >> x && x != 0)
		a[x] ++;
	for (int i = 1; i < 10; i++)
		cout << a[i] << ' ';
	return 0;
}