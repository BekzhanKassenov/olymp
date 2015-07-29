#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

double mx(double a, double b)
{
	if (a>b) return a;
	return b;
}

int main()
{
	double t1,t2,k;
	int n;
	cin>>n>>t1>>t2>>k;
	double a,b;
	vector <vector <double> > m(n,vector <double> (2,0));
	for (int i=0;i<n;i++)
		{
			cin>>a>>b;
			m[i][0]=double(i);
			m[i][1]=mx((a*t1-(a*t1*k)/100+b*t2),(b*t1-(b*t1*k)/100+a*t2));
		}
   for (int i=n-1;i>=0;i--)
   	{
   		for (int j=0;j<i;j++)
   			if (m[j][1]<m[j+1][1])
   				{
   					double k=m[j][1];
   					m[j][1]=m[j+1][1];
   					m[j+1][1]=k;
   					k=m[j][0];
   					m[j][0]=m[j+1][0];
   					m[j+1][0]=k;
   				}
   	}
   for (int i=0;i<n;i++)
   	{
   		cout<<m[i][0]+1;
   		printf(" %.2lf",m[i][1]);
   		cout<<endl;
   	}
	return 0;
}
