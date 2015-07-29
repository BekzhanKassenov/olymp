#include <iostream>
#include <cstdio>

using namespace std;

int nod(int a, int b)
{
	if (a==b) return a;
	if (a>b) a=a-b;
	else b=b-a;
	return (nod(a,b));
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int a,b;
	cin>>a>>b;
	cout<<(a*b)/nod(a,b);
	return 0;
}
