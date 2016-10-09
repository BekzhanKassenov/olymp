#include <stdio.h>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
    scanf("%d",&n);
	int a[210];
	for (int i=0;i<210;i++)
	a[i]=0;
	int k;
	for (int i=0;i<n;i++)
	{
        scanf("%d",&k);
		a[k+105]++;
	}
	for (int i=0;i<210;i++)
	{
		for (int j=1;j<=a[i];j++)
        printf("%d ",i-105);
	}
	return 0;
}
