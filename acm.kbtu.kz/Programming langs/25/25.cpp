#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector <int> a;
	while (cin >> n && n != 0)
		{
			int ans = 0;
			int c;
			for (int i = 0; i < n; i++)
				{
					cin >> c;
					ans *= 10;
					ans += c;
				}
			a.push_back(ans);
		}
	cout << a.size() << endl;
	for (int i = 0; i < (int)a.size(); i++)
		cout << a[i] << ' ';
	return 0;
	return 0;
}
