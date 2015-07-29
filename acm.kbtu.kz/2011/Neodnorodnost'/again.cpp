#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int cd(char a)
{
if (a=='a') return 0;
if (a=='b') return 1;
if (a=='c') return 2;
if (a=='d') return 3;
if (a=='e') return 4;
if (a=='f') return 5;
if (a=='g') return 6;
if (a=='h') return 7;
if (a=='i') return 8;
if (a=='j') return 9;
if (a=='k') return 10;
if (a=='l') return 11;
if (a=='m') return 12;
if (a=='n') return 13;
if (a=='o') return 14;
if (a=='p') return 15;
if (a=='q') return 16;
if (a=='r') return 17;
if (a=='s') return 18;
if (a=='t') return 19;
if (a=='u') return 20;
if (a=='v') return 21;
if (a=='w') return 22;
if (a=='x') return 23;
if (a=='y') return 24;
if (a=='z') return 25;
}

int main()
{
freopen("again.in","r",stdin);
freopen("again.out","w",stdout);
int a [26];
string str;
cin>>str;
int len=str.length();
for (int i=0; i<=25;i++)
a[i]=0;
for (int i=0;i<len;i++)
{
	a[cd(str[i])]++;
}
int maxm=a[cd(str[0])];
int minm=a[cd(str[0])];
for (int i=0; i<=25;i++)
	{
		if ((a[i]<minm) && (a[i]!=0))
			{	
				minm=a[i];
			}
		if ((a[i]>maxm) && (a[i]<=100))
			{	
				maxm=a[i];
			}
	}
cout<<maxm-minm;
fclose(stdin);
fclose(stdout);
return 0;
}
