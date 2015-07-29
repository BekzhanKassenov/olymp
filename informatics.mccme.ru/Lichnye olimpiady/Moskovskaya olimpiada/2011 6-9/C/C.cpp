#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	int x, y, x1, y1, x2, y2, x3, y3;
	for (int i = 0; i < n; i++)
		{	
			cin >> x >> y >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			if ((x + x1 == x2 + x3 && y + y1 == y2 + y3) ||
				 (x + x2 == x1 + x3 && y + y2 == y1 + y3) ||
				 (x + x3 == x1 + x2 && y + y3 == y1 + y2))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	return 0;
}
