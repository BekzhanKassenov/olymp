
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int a[1000001];

int main()
{
	int n, p;

	cin >> n >> p;

	int x; 

	for (int i = 0; i < n; i++)
		{
			cin >> x;
			a[x] ++;
		}

  	int k = 0;

  	int ans1 = 0, ans2 = 0;

 	for (int i = 0; i < 1000001; i++)
 		{
 			if (a[i] != 0)
 				{
 					int tmp = k;

 					tmp += a[i];

 					if (tmp * i <= p)
 						{
 							k = tmp;
 							continue;
 						}
 					else
 						{
 							if (k != 0)
 								{
 									ans1 += k;
 									ans2 ++;
 								}

 							if (a[i] * i <= p)
 								k = a[i];
 							else
 								{
 									k = 0;
 									break;
 								}

 						}	
 				}
 		}

 	if (k != 0)
 		{
 			ans1 += k;
 			ans2++;
 		}
 	cout << ans1 << ' ' << ans2;
 	return 0;
}


