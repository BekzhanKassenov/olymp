#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector <long long> vc;
typedef long long ll;

vc sum(const vc& a, ll k)
{
	vc ans;
	ll flag = 0;
	for (int i=0;i<a.size();i++)
		{
			flag+=a[i];
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

vc prv( const vc& a, ll k)
{
	vc ans;
	ll flag = 1;
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

bool operator < (const vc& a ,const vc& b)
{
	int i = 0;
	int lena = a.size(), lenb = b.size();
	if (lena!=lenb)
		return (lena<lenb);
	while (a[i]==b[i] && i<lena) 
		i++;
	if (i!=lena-1)
		a[i]<b[i];
	else
		return false;
}

int main()
{
	long long k,z,n,t;
	cin >> k >> z >> n >> t;
	vc a,b;
	a.push_back(1);
	for (int i=0;i<n;i++)
		{
			a = prv(a,k);
			a = sum(a,z);
		}
	while (t>0)
		{
			b.push_back(t%10);
			t/=10;
		}
   ll i = 0;
	while (b<a)
		{
			b = prv(b,k);
			b = sum(b,z);
		}
	cout << i << endl;
}