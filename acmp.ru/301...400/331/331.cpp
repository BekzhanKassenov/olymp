#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int h1,h2,m1,m2,a1,a2;
	char c;
	cin >> h1 >> c >> m1;
	cin >> h2 >> m2;
	a1 = h1;
	a2 = m1;
	while (h2>0 || m2>0)
		{
			a2++;
			if (a2>=60)
				{
					a2 = 0;
					a1++;
						if (a1>=24)
							{
								a1 = 0;
								a2 = 0;
							}
				}
			m2--;
			if (m2<0)
				{
					m2 = 59;
					h2--;
				}
		}
  	if (a1<10)
   	cout << 0;
	cout << a1 << c;
   if (a2<10)
   	cout << 0;
   cout << a2;
  	return 0;
}
