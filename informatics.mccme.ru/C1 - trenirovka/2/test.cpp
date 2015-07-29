#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	float x,y;
	cin >> x >> y;
	if (y >= -1 && y <= 0 && y <= cos(x) && x >= -1.57 && x <= 1.57)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
