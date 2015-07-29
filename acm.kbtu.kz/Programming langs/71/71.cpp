#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << n << endl;

	int x;
	string s;
	for (int i = 0; i < n; i++)
		{
			cin >> x >> s;
			x++;
			cout << x << ' ' << s << endl;
		}
	return 0;
}
