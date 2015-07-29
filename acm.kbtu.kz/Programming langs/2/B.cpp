#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((a + b) % 2 == (c + d) % 2)
		cout << "YES";
	else
		cout << "NO";
  	return 0;
}
