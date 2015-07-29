#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int n,m;
	
	cin >> n >> m;
	
	if (n == 1)
		{
			int x;

			cin >> x;

			cout << m + x;
			return 0;
		}

	priority_queue <int> s;

	int tmp;

	for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			s.push((-1) * tmp);
		}


	for (; ;)
		{
			int p = (-1) * s.top();

			s.pop();

			int pl = (-1) * s.top() - p + 1;

			if (pl > m)
				{
					pl = m;

					p += pl;

					s.push((-1) * p);

					break;
				}

			p += pl;

			m -= pl;

			s.push((-1) * p);

			if (m == 0)
				break;
		}

	cout << ((-1) * s.top());

   return 0;
}
