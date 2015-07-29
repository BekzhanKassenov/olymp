#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int len = a.length();
	int ans = 0;
	for (int i = 0; i < (int)b.length(); i++)
		{
			if (b.substr(i, len) == a)
				ans++;
		}
	cout << ans;
	return 0;
}
