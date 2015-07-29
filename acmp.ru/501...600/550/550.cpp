#include <iostream>
#include <cstdio>

using namespace std;

void writetr(int n)
{
	if (n<10 && n>=0)
		{
			cout<<"000"<<n;
			return;
		}
	if (n>=10 && n<100)
		{
			cout<<"00"<<n;
			return;
		}
	if (n>=100 && n<1000)
		{
			cout<<0<<n;
			return;
		}
	cout<<n;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	if ((n%400==0) || ((n % 4 == 0) && (n % 100 !=0)))
		cout<<"12/09/";
	else cout<<"13/09/";
	writetr(n);
	return 0;
}
