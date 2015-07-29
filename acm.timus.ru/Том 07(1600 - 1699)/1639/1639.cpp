#include <iostream>

using namespace std;

int main()
{
	int x, y;

	cin >> x >> y;

	if ((x * y) % 2 == 1)
		cout << "[second]=:]";
	else
		cout << "[:=[first]";
	
	return 0;
}
