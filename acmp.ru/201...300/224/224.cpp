#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int n;
	cin >> n;
	long long s1 , s2 , s3 , s4 , s5;
		{
			long long z1 , z2 , z3;
			cin >> z1 >> z2 >> z3;
			s1 = max ( max ( z1 , z2 ) , z3);
			s3 = min ( min ( z1 , z2 ) , z3);
			s2 = z1 + z2 + z3 - s1 - s3;
			s4 = s2;
			s5 = s3;
		}
	for (int i = 3 ;i < n; i++)
		{
			long long z;
			cin >> z;
			if (z > s1)
				{
					s3 = s2;
					s2 = s1;
					s1 = z;
				}	
			else 
				{
					if (z > s2)
						{
							s3 = s2;
							s2 = z;
						}
					else
						{
							if (z > s3)
								{	
									s3 = z;
								}
						}
			   }
			if (z < s5)
				{
					s4 = s5;
					s5 = z;
				}
			else
				{
					if (z < s4)
						{
							s4 = z;
						}
			   }
		}
	cout << max( s1 * s2 * s3 , s1 * s4 * s5);
	return 0;
}
