#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	int a0,b0;
	a0 = m/2;
	b0 = m/2+1+m%2;
	if (m%2==1)
		{
			cout << m/2+1 << "\n";
			n--;
		}
	if (m==1)
		{
			for (int i=0;i<n;i++)
				cout << 1 << endl;
			return 0;
		}
	int a = a0, b = b0;
   while (true)
   	{	
   		cout << a << "\n";
   		n--;
   		a--;
   		if (a==0)
   			a = a0;
   		if (n<=0)
   			break;
   		cout << b << "\n";
   		b++;
   		n--;
   		if (n<=0)
   			break;
   		if (b>m)
   			{
   				b = b0;
   				if (m%2==1)
   				{
   					cout << m/2+1 << "\n";
   					n--;
   				}
   			}
   		if (n<=0)
   			break;
   	}
  	return 0;
}
