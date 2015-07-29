#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string int_to_str(int n)
{
	int c=n;
	string ans;
	while (c>0)
		{
			ans+=char(c%10 + '0');
			c/=10;
		}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,k;
	cin>>n>>k;
	string s=int_to_str(k);
	vector <string> a(n);
	for (int i=0;i<n;i++)
		a[i]=int_to_str(i+1);
	sort(a.begin(),a.end());
	for (int i=0;i<n;i++)
		if (a[i]==s) 
			{
				cout<<i+1;
				break;
			}
	return 0;
}
