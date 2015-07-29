#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	double a, b;

	cin >> a >> b;

	int k;
	
	cin >> k;

	double ans = -1000000000;

	int ans1 = 20000000;
	int ans2 = ans1;

	for (int i = 0; i <= k; i++)
		{
			for (int j = 0; j + i <= k; j++)
				{
					double tmp = (i * a + j * b) - (i * i + j * j);
					
					if (ans < tmp)
						{
							ans = tmp;
							ans1 = i;
							ans2 = j;
						}
					if (ans == tmp)
						{
							if (i < ans1)
								{
									ans1 = i;
									ans2 = j;
								}
							else
								if (i == ans1 && j < ans2)
									{
										ans2 = j;
										ans1 = i;
									}  	
						}
				}
		}

	printf("%.2lf\n%d %d", ans, ans1, ans2);
	return 0;
}
