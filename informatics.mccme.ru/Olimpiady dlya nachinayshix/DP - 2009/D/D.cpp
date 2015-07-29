#include <iostream>
#include <string>

using namespace std;

string s;

int i;

int len;

int str_to_int(string s)
{
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
		{
			ans *= 10;
			ans += s[i] - '0';
		}
	return ans;
}

int nextInt()
{
	while ((s[i] < '0' || s[i] > '9') && i < len)
		i++;
	string ans;
	while (s[i] >= '0' && s[i] <= '9' && i < len)
		{
			ans += s[i];
			i++;
		}
	return str_to_int(ans);
}

int main()
{
	i = 0;
	cin >> s;
	len = s.size();
	while (i < len)
		{
			int a = nextInt();
			if (a > 5)
				{
					cout << "NO";
					return 0;
				}
		}
	cout << "YES";
	return 0;
}

