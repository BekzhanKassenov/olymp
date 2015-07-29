#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector <int> vc;

void writeln(const vc& a)
{
	for (int i = a.size()-1;i>=0;i--)
		cout << a[i];
	cout << endl;
}

vc sum(const vc& a, const vc& b)
{
	vc ans;
	int flag = 0;
	int lena = a.size(), lenb = b.size();
	for (int i=0;i<min(lena,lenb);i++)
		{
			flag += (a[i] + b[i]);
			ans.push_back(flag%10);
			flag/=10;
		}
	if (lena<lenb)
		{
			for (int i=lena;i<lenb;i++)
				{
					flag += b[i];
					ans.push_back(flag%10);
					flag/=10;
				}
		}
	if (lena>lenb)
		{
			for (int i=lenb;i<lena;i++)
				{
					flag += a[i];
					ans.push_back(flag%10);
					flag/=10;
				}
		}
	while (flag>0)
		{
			ans.push_back(flag%10);
			flag/=10;
		}
	 return ans;
}

vc prv(vc& a, long long k)
{
	long long flag = 0;
	vc ans;
	for (int i=0;i<a.size();i++)
		{	
			flag += a[i]*k;
			ans.push_back(flag%10);
			flag/=10;
		}
	while (flag>0)
		{
			ans.push_back(flag%10);
			flag/=10;
		}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long long n;
	cin >> n;
	vc ans, fc;
	fc.push_back(1);
	ans.push_back(0);
	for (long long i=1;i<=n;i++)
		{
			fc = prv(fc,i);
			ans = sum (ans,fc);
		}
	writeln(ans);
	return 0;
}
