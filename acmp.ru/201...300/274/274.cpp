#include <iostream>
#include <cstdio>

using namespace std;

bool test(int x, int y)
{
	int s1=0, s2=0;
   int c=x;
   while (c>0)
   	{
   		s1=s1 | (1 << ( c % 10 ) );
   		c /= 10;
   	}
   c=y;
   while (c>0)
   	{
   		s2=s2 | (1 << ( c % 10 ) );
   		c /= 10;
   	}
   if (s1==s2)
   	return true;
   return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			if (test(x,y)) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	return 0;
}
