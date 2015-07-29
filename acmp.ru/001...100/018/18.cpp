#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector <int> prv(vector <int> a, int m)
{
	vector <int> ans;
	long long flag=0;
	for (int i=0;i<a.size();i++)
		{
			flag+=(long long)(a[i]*m);
			ans.push_back(int(flag%10));
			flag/=10;
		}
	while (flag>0)
		{
			ans.push_back(int(flag%10));
			flag/=10;
		}
	return ans;
}

void writeln(vector <int> a)
{
	for (int i=a.size()-1;i>=0;i--)
		cout<<a[i];
	cout<<endl;	
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector <int> ans;
	ans.push_back(1);
	for (int i=1;i<=n;i++)
		ans=prv(ans,i);
	writeln(ans);     
	return 0;
}
