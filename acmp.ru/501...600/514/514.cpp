#include <iostream>
#include <cstdio>

using namespace std;

int main()
{	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int i=1;
	while (n>=0)
		{
			n-=i;
			i++;
		}
	cout<<i-2;
	return 0;
}
