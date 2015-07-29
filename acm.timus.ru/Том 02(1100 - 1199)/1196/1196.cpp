#include <cstdio>
#include <set>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);
	set <int> s;

	int tmp;

	for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);

			s.insert(tmp);
		}

	scanf("%d", &n);

	int ans = 0;

	for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);

			if (s.find(tmp) != s.end())
				ans++;
		}

	printf("%d", ans);
	return 0;
}
