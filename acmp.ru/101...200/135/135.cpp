#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int inf=99999999;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector <vector <int> > d(n, vector <int> (n));
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin>>d[i][j];
	for (int k=0;k<n;k++)
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
				cout<<d[i][j]<< ' ';
			cout<<endl;
		} 
	return 0;
}
