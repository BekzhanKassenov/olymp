#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (c < a)
		{
			cout << "NO GRAD";
			return 0;
		}
	if (a <= c && c < b)
		cout << "GRAD";
	return 0;
}
