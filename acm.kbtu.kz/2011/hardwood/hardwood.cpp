#include <iostream>
#include <cstdio>

using namespace std;

int d[512][512];
int m,n;

int bit(int x,int i)
{
	int k=x & (1 << i); 
	if (k==0)
		return 0;
	return 1;
}

void go(int p, int profile, int len)
{
if (len>=m) 
{
d[p][profile]=1;
return;
}
else 
  {
    if (bit(p,len)==0)
      {
        if (bit(profile,len)==0)
          {
            go(p,profile + (1 << len),len+1);
	    	if ((bit(profile,len+1) == 0) && len<m-1)
	      		{
				go(p,(profile + (1 << len) + (1 << (len +1))),len+1);
	      		} 
	    	if ((bit(profile,len-1)== 0) && (len>=1))
	      		{
				go(p,(profile + (1 << len) + (1 << (len -1))),len+1);
	      		}
	  }	
	if (len < m-2)
	   if (bit(p,len+1)==0)
		{
			go(p,profile,len+2);
			if (bit(profile,len+1)==0)
				go(p,profile + (1<<(len + 1)),len+2);
			if (bit(profile,len)==0)
				go(p,profile + (1 << len),len+2);
		}
      }
  else
	go(p,profile,len+1);
  }
}  	
				

        

int main()
{
	cin>>m>>n;
	if ((m==1) && (n==1))
		{
			cout<<0;
			return 0;
		}

	for (int i=0;i<=(1 << m)-1;i++)
		{
			go(i,0,0);
		}

	long a [8][511];
	a[1][0]=1;
	for (int i=1; i<=(1 << m) - 1;i++)
		{
			a[1][i]=0;
			for (int k=0; k<=(1 << m) -1;k++)
				a[1][i]+=d[k][i];
		}
	a[0][0]=0;
for (int i=2;i<=n+1;i++)
for (int j=0;j<=(1 << m)-1;j++)
{
a[i][j]=0;
for (int k=0;k<=(1 << m) -1;k++)
a[i][j]+=a[i-1][k]*d[k][j];
}
cout<<a[n+1][0];
return 0;
}
