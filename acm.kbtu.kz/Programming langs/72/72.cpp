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
			cin >> s >> x;
			x++;
			cout << s << ' ' << x << endl;
		}
	return 0;
}
