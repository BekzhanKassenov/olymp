#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	scanf("%d", &n);

	stack <int> st;

	int mx = 0;

	for (int j = 0; j < n; j++)
		{
			int tmp;

			scanf("%d", &tmp);

			if (st.empty())
				{
					for (int i = 1; i < tmp; i++)
						{
							st.push(i);
						}

					mx = tmp;
					continue;
				}
			if (tmp > st.top())
				{
					for (int i = mx + 1; i < tmp; i++)
						st.push(i);
					mx = tmp;
				}
			else
				if (tmp == st.top())
					st.pop();
				else
					{
						cout << "Cheater";
						return 0;
					}	

		}

	cout << "Not a proof";
	return 0;
}
