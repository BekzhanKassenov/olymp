#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

vector <int> dec_to(int n, int p)
{
	vector <int> ans;
	while (n)
		{
			ans.push_back(n % p);
			n /= p;
		}

	return ans;
}

bool check(vector <int> v)
{
	set <int> s(v.begin(), v.end());

	if (s.size() == v.size())
		return true;

	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	for (int i = 2; i <= 36; i++)
		{
			vector <int> tmp = dec_to(n, i);

			if (check(tmp))
				{
					cout << i << ' ';
				}
		}

	return 0;	
}
