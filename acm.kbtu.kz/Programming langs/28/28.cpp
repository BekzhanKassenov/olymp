#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n + 1);

	for (int i = 0; i < n; i++)
		cin >> a[i];
	int b, c;
	cin >> b >> c;

	for (int i = n; i >= b; i--)
		a[i] = a[i - 1];
	a[b - 1] = c;
	for (int i = 0; i < n + 1; i++)
		cout << a[i] << ' ';
	return 0;	
}
