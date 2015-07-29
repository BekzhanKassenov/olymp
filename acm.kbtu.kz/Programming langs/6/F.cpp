#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector <int> a;
	int ans = 0;
	while (cin >> n)
		{
			a.push_back(n);
			if (ans > 0 && a[ans - 1] == a[ans])
				{
					cout << ans + 1;
					return 0;
				}
			ans++;
		}
	cout << ans;
	return 0;
}


