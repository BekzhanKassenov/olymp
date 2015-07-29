#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (a==b)
		return a;
	if (a < b)
		return gcd(b-a,a);
	if (a > b)
		return gcd(a-b,b);
}

int iabs(int a)
{
	return (a<0)?(-a):a;
}

int main()
{
	int n,m;
	cin >> n >> m;
	int a,b,c;
	cin >> a;
	for (int i=1;i<=n;i++)
		cin >> c;
	cin >> b;
	for (int i=1;i<=m;i++)
		cin >> c;
	if (n<m)
		{
			cout << 0 << '/' << 1;
			return 0;
		}
	if (n==m)
		{
			c = gcd(iabs(a),iabs(b));
			if (a*b<0)
			cout << '-';
			cout << iabs(a/c) << '/' << iabs(b/c);
			return 0;
		}
	if (n>m)
		{
			if (a*b<0)
				cout << "-Infinity";
			else
				cout << "Infinity";
			return 0;
		}
	return 0;
}
