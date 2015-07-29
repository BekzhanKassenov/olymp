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

	int ans = 0;

	for (int i = 0; i < n; i++)
		if ((i + 1) % 2 == 0 && a[i] % 2 == 0)
			ans++;
	cout << ans;
	return 0;
}
