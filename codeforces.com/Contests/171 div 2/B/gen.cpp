#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cout << "100000 1000000000" << endl;

	for (int i = 0; i < 100000; i++)
		{
			cout << "1000000000";
			if (i != 99999)
				cout << ' ';

			else
				cout << endl;
		}	

	return 0;
}
