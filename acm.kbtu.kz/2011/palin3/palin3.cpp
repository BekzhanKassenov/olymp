#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool pal(string s)
{
int len=s.length();
if (len==1) return false;
for (int i = 0;i<len/2;i++)
if (s[i]!=s[len-i-1]) return false;
return true;
}


int half(string s)
{
int len=s.length();
int k;
if (pal(s))
{
if ((len % 2)==0)
k=0;
else k=1;
len=len/2;
string str=s.substr(0,len+k);
return (half(str)+1);
}
return 0;
}

int main()
{
freopen("palin3.in","r",stdin);
freopen("palin3.out","w",stdout);
string s;
cin>>s;
cout<<half(s);
return 0;
}
