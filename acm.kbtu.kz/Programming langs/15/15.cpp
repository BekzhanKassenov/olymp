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
   for (int i = 0; i < n; i++)
   	if (a[i] % 2 == 1)
   		cout << a[i] << ' ';
   for (int i = 0; i < n; i++)
   	if (a[i] % 2 == 0)
   		cout << a[i] << ' ';
	return 0;
}
