#include <iostream>
#include <cstdio>

using namespace std;

int absm(int a)
{
	if (a<0) return -a;
	return a;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char a,b;
	a=getchar();
	b=getchar();
	int k=a-'a'+1;
	int m=b-'0';
	for (int i=1;i<=8;i++)
		for (int j=1;j<=8;j++)
			{
				if (absm(i-k)*absm(j-m)==2)
					cout<<char(i+'a'-1)<<char(j+'0')<<endl;
			}
	return 0;
}
