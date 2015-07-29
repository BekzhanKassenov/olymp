#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int cti(char a)
{
	switch (a)
	{
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case 'A': return 1;
	case 'B': return 2;
	case 'C': return 3;
	case 'D': return 4;
	case 'E': return 5;
	case 'F': return 6;
	case 'G': return 7;
	case 'H': return 8;
	default: return -1;
	}
}

int test(string s)
{
	bool k=(s.length()==5);
	k=(k & (s[2]=='-'));
	k=(k & (s[0]>='A' && s[0]<='H' && s[1]>='1' &&  s[1]<='8'));
	k=(k & (s[3]>='A' && s[3]<='H' && s[4]>='1' &&  s[4]<='8'));
	if (k) return 0;
	return -1;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	cin>>s;
	if (test(s)==0)
		{
			int a=cti(s[0]);
			int b=cti(s[1]);
			int c=cti(s[3]);
			int d=cti(s[4]);
			a=a-c;
			if (a<0) a*=(-1);
			b=b-d;
			if (b<0) b*=(-1);
			if ((a==1 && b==2) || (a==2) && b==1)
			cout<<"YES";
			else
			cout<<"NO";
		}
   else cout<<"ERROR";
   return 0;
}
