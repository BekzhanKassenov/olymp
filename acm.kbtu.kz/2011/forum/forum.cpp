#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

string getsstr()
{
	string c,s;
	cin>>s;
	getline(cin,c);
	string k=s+c;
	return k;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector <int> a(n+3);
	vector <pair <string,int> > nzv(n);
	int uk=0;

	string s;
	for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			if (a[i]==0)
				{
					s=getsstr();
					nzv[uk].first=s;
					uk++;
					getsstr();
				}
		   else 
		   	{
		   		if (a[a[i]]!=0)
		   			a[i]=a[a[i]];
		   		getsstr();
		   	}
		   nzv[i].second=0;
		}

	int ans=0,k=0;
	

	for (int i=1;i<=n;i++)
		{
			int z=a[i];
			nzv[z].second++;
			if (nzv[z].second>ans)
				{
					ans=nzv[z].second;
					k=z;
            }
		}

	cout<<nzv[k-1].first;
	return 0;
}
