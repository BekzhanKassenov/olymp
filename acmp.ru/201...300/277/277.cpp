#include <iostream>
#include <cstdio>

using namespace std;

int iabs(int a)
{
	return (a<0)?(-a):a;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int a,b,c;
	cin >> a >> b >> c;
	if (a==0 && b==0 && c==0)
		{
			cout << 0;
			return 0;
	   }
	if (a!=0)
		{
			cout << a;
			if (b>0)
				cout << '+';
			else
				{	
					if (b==0 && c>0)
						cout << '+';
				}
		}
	if (b!=0)
		{
			switch(b)
			{
				case 1:	
					cout << 'x';
					break;
				case -1:
					cout << "-x";
					break;
				default:
					cout << b << 'x';
			}
			if (c>0)
				cout << '+';
		}
   if (c!=0)
   	{
   		switch(c)
			{
				case 1:	
					cout << 'y';
					break;
				case -1:
					cout << "-y";
					break;
				default:
					cout << c << 'y';
			}
   	}
   return 0;
}
