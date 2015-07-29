#include<stdio.h>
#include<string.h>

int n;
char s[1000005];
int main()
{
freopen("in", "r", stdin);
freopen("out", "w", stdout);
scanf("%s",s);
int n=strlen(s);
for(int i=0;i<n;i++)if(s[i]=='r')printf("%d\n",i+1);
for(int i=n-1;i>=0;i--)if(s[i]=='l')printf("%d\n",i+1);
return 0;
}