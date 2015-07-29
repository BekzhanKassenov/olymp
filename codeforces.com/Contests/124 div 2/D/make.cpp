#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("in","w",stdout);

	cout << "1500 1500" << endl;
	
	for (int i = 0; i < 1500; i++)   
		{
			for (int j = 0; j < 1500; j++)
				cout << '#';
			cout << endl;
		}
	return 0;	
}
