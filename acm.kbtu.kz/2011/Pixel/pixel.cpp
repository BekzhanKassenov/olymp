#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
freopen("pixel.in","r",stdin);
freopen("pixel.out","w",stdout);
int kr[500][1];
int n;
int w,h;
cin>>n>>w>>h;
int s=0;
cin>>kr[s][0]>>kr[s][1];
int x,y;
for (int i=1; i<n; i++)
{
  cin>>x>>y;
  if (x==kr[s][0])
	{
	    int a=min(y,kr[s][1]);
	    int b=max(y,kr[s][1]);
	    for (int j=a;j<=b;j++)
	      {
		s++;
		kr[s][0]=x;
		kr[s][1]=j;
	      }
	}

  if (y==kr[s][1])
	{
	   int a=min(x,kr[s][0]);
	   int b=max(x,kr[s][0]);
	   for (int j=a;j<=b;j++)
	      {
		s++;
		kr[s][1]=y;
		kr[s][0]=j;
	      }
	}
}

for (int i=0;i<=s;i++)
cout<<kr[i][0]<<" "<<kr[i][1]<<"\n";
return 0;
}
