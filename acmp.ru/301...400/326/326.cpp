#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector <int> vc;

int n;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	vector <int> a(n);
	for (int i=0;i<n;i++)
		cin>>a[i];
	vector <int> b=a;
	sort(b.begin(),b.end());
	int k=0, c=b[0], mx=0;
	int i=0;
	while (i<n)
		{
			do
				{
					k++;
					i++;
				}
			while (b[i]==b[i-1] && i<n);
			if (k>mx || (k==mx && b[i-1]<c)) 
				{
					c=b[i-1];
					mx=k;
			  	}
			k=0;
		}
	for (int i=0;i<n;i++)
		if (a[i]!=c)
			cout << a[i] << ' ';
	for (int i=0;i<mx;i++)
		cout << c << ' ';
   return 0;
}
