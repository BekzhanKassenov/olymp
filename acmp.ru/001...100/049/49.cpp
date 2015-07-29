#include <iostream>
#include <cstdio>
#include <string>  
#include <set>

using namespace std;

int absm(int a)
{
	if (a<0) return -a;
	return a;
}

int cht(char a, char b)
{
	if ((int)(a-'0')-int (b-'a')<=3)
		return (int)(a-'0')-int (b-'a');
	else return 0;
}

int sovm(char a,char b)
{
	set <char> k;
	string n;
	if (a=='?')
		{
			for (int i=0;i<=9;i++)
				k.insert(char(i+int('0')));
		}
	if (a>='a' && a<='z')
		{
			for (int i=0;i<4;i++)
				k.insert(char(int(a)-int('a')+int('0')+i));
		}
	if (a>='0' && a<='9')
		k.insert(a);
	if (b=='?')
		for (int i=0;i<=9;i++)
				n+=(char(i+int('0')));
   if (b>='a' && b<='z')
		for (int i=0;i<4;i++)
				n+=(char(int(b)-int('a')+int('0')+i));
	if (b>='0' && b<='9')
		n+=b;
	int ans=0;
	for (int i=0;i<n.length();i++)
		{
			if (k.find(n[i])!=k.end())  ans++;
		}
	return ans;

}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string a,b;
	cin>>a;
	cin>>b;
	int len=a.length();
	long long ans=1;
	for (int i=0;i<len;i++)
			ans*=(long long) (sovm(a[i],b[i]));
	cout<<ans;	
	return 0;
}

