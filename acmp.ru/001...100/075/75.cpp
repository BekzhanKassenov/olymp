#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void writeln(vector <int> a)
{
	for (size_t i=a.size()-1;i>0;--i)
		cout<<a[i];
	cout<<a[0];
	cout<<endl;
}

vector <int> prv(vector <int> a, int z)
{
	vector <int> b;
	if (z==0)
		{
			b.push_back(0);
			return b;
		}
	int flag=0;
	for (size_t i=0;i<a.size();i++)
		{
			flag+=a[i]*z;
			b.push_back(flag%10);
			flag/=10;
		}
	while (flag>0)
		{
			b.push_back(flag%10);
			flag/=10;
		}
	
	return b;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	if (n==0)
		{
			cout<<0;
			return 0;
		}
	vector <int> ans;
	ans.push_back(5);
	ans.push_back(4);
	for (int j=1;j<n;j++)
		ans=prv(ans,45);
	writeln(ans);
	return 0;
}
