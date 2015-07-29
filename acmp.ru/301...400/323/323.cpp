#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool prost(int n)
{
	if (n==1) return false;
	int k=int(sqrt(double(n)));
	for (int i=2;i<=k;i++)
		if (n % i == 0) return false;
	return true;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	for (int i=2;i<=n/2;i++)
		if (prost(i) && prost(n-i))
			{
				cout << i << ' ' << n-i;
				return 0;
			}
	return 0;
}
