#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector <int> vc;

void writeln(const vc& q)
{
	for (int i=q[0];i>0;i--)
		cout<<q[i]; 
	cout<<endl;
}



vc sm( const vc& a,const vc& b)
{
vc c;
int flag=0;
int i;
int s=0;
c.push_back(0);
for (i=1;i<=max(a[0],b[0]);i++)
	{	
		c.push_back((a[i]+b[i]+flag)%10);
		if ((a[i]+b[i]+flag)>=10) flag=1;
		else flag=0;
		s++;
	}
if (flag==1)
{
	c.push_back(1);
	s++;
}	
c[0]=s;	
return c;
}


int main()
{
	vc a(170,0);
	vc b(170,0);
	a[0]=5;
	a[1]=5;
	a[2]=9;
	a[3]=3;
	a[4]=7;
	a[5]=8;
	b[0]=8;
	b[1]=1;
	b[2]=8;
	b[3]=3;
	b[4]=6;
	b[5]=8;
	b[6]=1;
	b[7]=9;
	b[8]=4;
	writeln(a);
	writeln(b);
	for (int i=0;i<25;i++)
		{
			a=sm(a,b);
			writeln(a);
		}
 	return 0;
}
