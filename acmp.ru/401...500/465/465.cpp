#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector <int> vc;

void writeln(vc a)
{
	for  (int i=a.size()-1;i>=0;i--)
		cout<<a[i];
	cout<<endl;
}

vc sum (vc a, vc b)
{
	int flag=0;
	vc c;
	for (int i=0;i<min(a.size(),b.size());i++)
		{
			flag+=a[i]+b[i];
			c.push_back(flag%10);
			flag/=10;
		}
	if (a.size()>b.size())
		{
			for (int i=b.size();i<a.size();i++)
				{
					flag+=a[i];
					c.push_back(flag%10);
					flag/=10;
				}
		}
	if (a.size()<b.size())
		{
			for (int i=a.size();i<b.size();i++)
				{
					flag+=b[i];
					c.push_back(flag%10);
					flag/=10;
				}
		}
	while (flag>0)
		{	
			c.push_back(flag%10);
			flag/=10;
		}
	return c;

}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vc f1, f2, f;
	f1.push_back(1);
	f2.push_back(1);
	for (int i=0;i<n;i++)
		{
			f=sum(f1,f2);
			f2=f1;
			f1=f;
		}
	writeln(f);
	return 0;
}
