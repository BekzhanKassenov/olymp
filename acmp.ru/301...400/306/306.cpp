#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solve(int n, char c)
{
	int cnt = 0;

	bool flag = true;

	string ans;

	int i = 0;

	for (int i = 0; i < n; i++)
		ans += 1;

	while (cnt < n)
		{
			if (ans[i] == 1)
				if (flag)
					{
						flag = false;
						ans[i] = c;

						cnt++;
					
						if (c == 'R')
							c = 'B';
						else
							c = 'R';


					}	
				else
					flag = true;
					
			i = (i + 1) % n;
		}
  return ans;
}	

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	string s = solve(n, 'B');

	cout << s;

	return 0; 
}
