#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	scanf("%d", &n);

	int sz = (n >> 1) + 1;

	priority_queue <int> q;

	int cnt = 0;

	int tmp;

	int mx = -1;

	for (int i = 0; i < n; i++)	
		{	
			scanf("%d", &tmp);
			if (cnt < sz)
				{
					cnt++;
					q.push(tmp);
					mx = max(mx, tmp);
				}
			else
				{
					if (tmp < q.top())
						{
						//	cout << q.top() << endl;;
							q.pop();
							q.push(tmp);
						}
				}
		}	

	if (n % 2 == 0)
		{
			double t = (double)q.top();
			q.pop();
			double t1 = (double)q.top();

			//cout << t1 << ' ' << t << endl;

			printf("%.1lf", (t + t1) / 2);
		}
	else
		printf("%.1lf", (double) q.top());

	return 0;
}
	
