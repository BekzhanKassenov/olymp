#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int b;
	cin >> b;
	for (int i = b - 1; i < n - 1; i++)
		a[i] = a[i + 1];
	for (int i = 0; i < n - 1; i++)
		cout << a[i] << ' ';
	return 0;
}
