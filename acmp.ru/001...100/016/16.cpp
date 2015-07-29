#include <iostream>
#include <cstdio>

using namespace std;

long long s=0;

void clc(int n, int k)
{
	if (n<0) return;
	if (n==0) 
	{
		s++;
		return;
   }
	for (int i=k+1;i<=n;i++)
		clc(n-i,i);
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	clc(n,0);
	cout<<s;
	return 0;
}

