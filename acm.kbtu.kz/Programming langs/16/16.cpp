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
	for (int i = 0; i < n; i += 2)
		cout << a[i] << ' ';
	for (int i = 1; i < n; i += 2)	
		cout << a[i] << ' ';
	return 0;
}
