#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ll n;
	cin >> n;
	ll fn, f3 = 1, f2 = 2, f1 = 4;
	if (n == 1)
		{
			cout << 1;
			return 0;
		}
	if (n == 2)
		{
			cout << 2;
			return 0;
		}
	if (n == 3)
		{
			cout << 4;
			return 0;
		}
	for (ll i = 3; i <n; i++)
		{
			fn = f1 + f2 + f3;
			f3 = f2;
			f2 = f1;
			f1 = fn;
		}	
	cout << fn;
	return 0;
}
