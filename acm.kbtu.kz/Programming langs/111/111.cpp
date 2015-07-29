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
	int s, f;
	cin >> s >> f;
	s--, f--;

	int k = a[s];
	int z = a[f];

	for (int i = 0; i < n; i++)
		if (a[i] == k)
			a[i] = z;

  	for (int i = 0; i < n; i++)
  		cout << a[i] << ' ';

  	return 0;
}
