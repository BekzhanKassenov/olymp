#include <iostream>
#include <cstdio>


using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	int c;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)	
			{
				cin >> c;
				if (i == j && c == 1)
					{
						cout << "YES";
						return 0;
					}
			}
	cout << "NO";
	return 0;
}
