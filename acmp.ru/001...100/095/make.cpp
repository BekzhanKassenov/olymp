#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","w",stdout);
	int n=1;
	for (int i=1;i<=1000;i++)
		{
			cout<<n;
			n++;
			n=n%10;
		}
	return 0;
}
