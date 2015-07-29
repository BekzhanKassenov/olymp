#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int b=n/5;
	int a=n%5;
	while (a%3!=0)
		{
			b-=1;
			a+=5;
		}	
	cout<<b<<" "<<a/3;
	return 0;
}
