#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void print(const vector <int> & a)
{
	for (int i = a.size() - 1; i >= 0; i--)
		printf("%d", a[i]);

	printf("\n");
}

vector <int> operator + (const vector <int>& a, const vector <int> & b)
{
	int flag = 0;

	int lena = a.size(), lenb = b.size();

	vector <int> ans;

	ans.reserve(max(lena, lenb) + 1);

	for (int i = 0; i < min(lena, lenb); i++)
		{
			flag += a[i] + b[i];

			ans.push_back(flag % 10);

			flag /= 10;
		}

	for (int i = min(lena, lenb); i < max(lena, lenb); i++)
		{
			if (lena < lenb)
				{
					flag += b[i];
				}

			else
				{
					flag += a[i];
				}

			ans.push_back(flag % 10);

			flag /= 10;
		}

	while (flag)
		{
			ans.push_back(flag % 10);
			flag /= 10;
		}

	return ans;	
}

vector <int> operator * (const vector <int> &a, int m)
{
	int flag = 0;

	vector <int> ans;

	for (int i = 0; i < (int)a.size(); i++)
		{
			flag += a[i] * m;
			ans.push_back(flag % 10);
			flag /= 10;
		}

	while (flag)
		{
			ans.push_back(flag % 10);
			flag /= 10;
		}

	/*print(a);

	printf(" * %d = \n ", m);

	print(ans); */

	return ans;
}

int main()
{
	freopen("out", "w", stdout);

	int n;

	cin >> n;

	vector <int> b, c, q, ed;

	b.push_back(1), q.push_back(1), c.push_back(1), ed.push_back(1);

	for (int i = 1; i <= n; i++)
		{
			b = b * 2, c = c * 3, q = q * 4;

			vector <int> res = b + c;

			res = res + q;
			res = res + ed;

			int ans1 = 0;

			int j = 0;

			while (res[j++] == 0)
				ans1++;

			int ans = -1;
			
			if (i % 4 == 0)
				{
					ans = 0;
				}
			
			if (i % 4 == 1 || i % 4 == 2)
				{
					ans = 1;
				}

			if (i % 4 == 3)
				{
					ans = 2;
				}

			if (ans1 != ans)
				{
					printf("ERROR ans = %d, ans1 = %d, power = %d, number = ", ans, ans1, i);

					print(res);
				}

	  }


	return 0;

}

