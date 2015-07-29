#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int r(string a,string b)
{
	int len=a.length();
	int ans=0;
	for (int i=0;i<len;i++)
		{
			if (a[i]!=b[i]) ans++;
		}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string c;
	string s;
	int n;
	cin>>s;
	cin>>n;
	vector <int> a(n,0);
	int mn=90099;
	for (int i=0;i<n;i++)
		{
			cin>>c;
			a[i]=r(s,c);
			if (a[i]<mn) mn=a[i];
		}
	int ans=0;
	for (int i=0;i<n;i++)
		if (a[i]==mn) ans++;
	cout<<ans<<endl;
	for (int i=0;i<n;i++)
		if (a[i]==mn) cout<<i+1<<" ";
	return 0;
}
