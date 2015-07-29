#include <cstdio>

using namespace std;

int s;

int a[50];


void init()
{
	for (int i=0;i<50;i++)
		a[i]=0;
	s=0;
	return;
}

void clc(int n,int k)
{
	if (n<0) return;
	if (n==0) 
	{
		printf("%d",a[0]);
		for (int i=1;i<s;i++)
			printf("%c%d",'+',a[i]);
		printf("\n");
		return;
   }
   if (k==0) 
   {
   	for (int i=1;i<n;i++)
			{
				a[s]=i;
				s++;
				clc(n-i,i);
				s--;
			}
		return;
	}
	for (int i=k;i<=n;i++)
		{
			a[s]=i;
			s++;
			clc(n-i,i);
			s--;
		}
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	init();
	clc(n,0);
	return 0;
}

