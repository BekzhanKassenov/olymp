#include <iostream>

using namespace std;

int main()
{
	cout << 500 << ' ' << 500 << endl;

	for (int i = 0; i < 500; i++)
		{
			for (int j = 0; j < 500; j++)
				cout << 1 << ' ';

			cout << endl;	
		}
	return 0;	
}
