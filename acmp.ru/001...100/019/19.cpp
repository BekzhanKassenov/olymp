#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int xf,yf,xl,yl,xk,yk;

int chtoint(char a)
{
	if (a=='A') return 1;
	if (a=='B') return 2;
	if (a=='C') return 3;
	if (a=='D') return 4;
	if (a=='E') return 5;
	if (a=='F') return 6;
	if (a=='G') return 7;
	if (a=='H') return 8;
	if (a=='1') return 1;
	if (a=='2') return 2;
	if (a=='3') return 3;
	if (a=='4') return 4;
	if (a=='5') return 5;
	if (a=='6') return 6;
	if (a=='7') return 7;
	if (a=='8') return 8;
}

bool test(int i,int j)
{
	if ((i==xf) && (j==yf)) return false;
	if ((i==xl) && (j==yl)) return false;
	if ((i==xk) && (j==yk)) return false;
	return true;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string f,l,k;
	cin>>f>>l>>k;
	xf=chtoint(f[0]);
	yf=chtoint(f[1]);
	xl=chtoint(l[0]);
	yl=chtoint(l[1]);
	xk=chtoint(k[0]);
	yk=chtoint(k[1]);
	int ans=0;
	for (int i=1;i<=8;i++)
		{
			for (int j=1;j<=8;j++)
				{
					if (test(i,j))
						{
							if ((i==xf) || (j==yf) || (i==xl) || (j==yl))
								{
									ans++;
									continue;
								}
							if (abs(i-xf)==abs(j-yf))
								{
									ans++;
									continue;
								}
							if (abs((i-xk)*(j-yk))==2)
								{
									ans++;
									continue;
								}
						}
				}
		}
   cout<<ans;
   return 0;
}

