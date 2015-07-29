#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a=1, b=2;
	for (int i=0;i<n;i++)
		{
			long long k;
			cin >> k;
			if (k==1)
				{
					cout << 3 << ' ';
					continue;
				}
			if (k%2==0)
				cout << 4*k+1 << ' ';
			else
				{
					if ((k/2)%2==1)
						cout << k+1 << ' ';
					else 
						cout << 2*k+1 << ' ';
				}
		}
	return 0;
}
