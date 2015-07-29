#include <iostream>


using namespace std;

int main()
{
	int n;
	cin >> n;
	int mn = 1000000000;

	for (int i = 0; i < n; i++)
		{	
			int x;
			cin >> x;
			mn = min(x, mn);
		}
	cout << mn;
	return 0;
}
