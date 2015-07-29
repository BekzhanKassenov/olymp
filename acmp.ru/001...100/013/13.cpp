#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string a,b;
	cin>>a>>b;
	int bk=0,kr=0;
	for (int i=0;i<=3;i++)
		{
			for (int j=0;j<=3;j++)
				{
					if (a[i]==b[j])
						{
							if (i==j) bk++;
							else kr++;
						}
				}
		}
  cout<<bk<<" "<<kr;
  return 0;
}
