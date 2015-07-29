#include <iostream>
#include <cstdio>

using namespace std;

int absm(int a)
{
	return a<0?(-a):a;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int x1,x2,y1,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if ((x1+y1)%2!=(x2+y2)%2)
		{
			cout << 0;
			return 0;
		}
	if (absm(x1-x2)==(absm(y1-y2)))
		{
			cout << 1;
			return 0;
		}
	cout << 2;
	return 0;
}
