#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long long n;
	cin>>n;
	if (n%2==1)
		cout<<n/2<< " "<<n-n/2;
	else
		{
			if ((n/2)%2==1)
				cout<<n/2-2<<" "<<n-n/2+2;
			else
				cout<<n/2-1<<" "<<n-n/2+1;
		}
	return 0;
}
