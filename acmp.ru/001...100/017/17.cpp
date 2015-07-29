#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

bool test(string s, int n)
{
	int len=s.length();
	int k=len/n;
	string a;
	a=s.substr(0,n);
	string z;
	for (int i=1;i<k;i++)
		{
			z=s.substr(i*n,n);
			if (z!=a) return false;
			a=z;
		}	
	return true;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	string s;
	cin>>n;
	n--;
	int c;
	for (int i=0;i<n;i++)
		{
			cin>>c;
			s+=c+'0';
		}
	int z=int(sqrt(double(n)));
	int a[101];
	int g=0;
	for (int i=1;i<=z;i++)
		{
			if (n%i==0) 
				if (test(s,i))	
					{
						cout<<i;
						return 0;
					}
				else 
					{
						a[g]=n/i;
						g++;
					}
		}
	for (int i=g-1;i>=0;i--)
		if (test(s,a[i]))
			{
				cout<<a[i];
				return 0;
			}
	
	return 0;
}
