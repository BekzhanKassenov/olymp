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
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	vector < vector <int> > a(302, vector<int> (400,0));
	int n;
	int k;
	cin>>k>>n;
	vc ed;
	ed.push_back(1);
	ed.push_back(1);
	a.push_back(ed);
	a[1]=ed;
	for (int i=2;i<=k;i++)
		{
			a[i]=sm(a[i-1],a[i-1]);	
		}
   
   	for (int i=k+1;i<=n;i++)
		{              
			int j=i-1;
			while	(j>=i-k && j>0)
				{	
					a[i]=sm(a[j],a[i]);
					j--;
				}	
		}
	writeln(a[n]);
	return 0;
}
      
