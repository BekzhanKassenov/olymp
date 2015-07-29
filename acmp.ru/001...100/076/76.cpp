#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int minutes(int a, int b)
{
	return a*60+b;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector <int> a(1450,0);
	for (int i=0;i<n;i++)
		{
			char c;
			int s,b,d,f;
			cin>>s>>c>>b>>d>>c>>f;;
			for (int i=minutes(s,b);i<=minutes(d,f);i++)
				a[i]++;
		}
	int ans=0;
	for (int i=0;i<1450;i++)
		ans=max(ans,a[i]);
	cout<<ans;	
	return 0;
}
