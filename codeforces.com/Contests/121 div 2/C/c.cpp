#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct zn
{
	string n;
	int len;
};

vector <zn> nm;
vector <zn> now;
int n;
long long ans=0;

void init()
{
	nm.resize(n);
}

void solve(int v)
{
	now.push_back(nm[v]);
	bool lg=false;
	for (int i=v+1;i<n;i++)
		if (nm[v].n[nm[v].len-1]==nm[i].n[0])
			{
				lg=true;
				solve(i);
			}
	if (!lg)
		{
			if (nm[v].n[nm[v].len-1]==now[0].n[0])
				{
					long long k=0;
					for (int i=0;i<now.size();i++)
						k+=now[i].len;
					ans=max(ans,k);
				}
		}
	now.erase(now.end()-1);
}

int main()
{
	cin>>n;
	init();
	for (int i=0;i<n;i++)
		{
			cin>>nm[i].n;
			nm[i].len=nm[i].n.length();
		}
	for (int i=0;i<n;i++)
		solve(i);
	cout<<ans;
	return 0;	
}
