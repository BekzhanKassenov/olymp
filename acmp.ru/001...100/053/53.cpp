#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	int green=0,red=0,blue=0,black=n*m;
	
	for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
				{
					
					if ((j*i)%5==0)
						{
							blue++;
							black--;
							continue;
						}	
					if ((j*i)%3==0)
						{
							green++;
							black--;
							continue;
						}	

					if ((j*i)%2==0) 
						{
							red++;
							black--;
							continue;
						}
				}     	
		}
						
	cout<<"RED : "<<red<<endl;
	cout<<"GREEN : "<<green<<endl;
	cout<<"BLUE : "<<blue<<endl;
	cout<<"BLACK : "<<black;
	return 0;
}

