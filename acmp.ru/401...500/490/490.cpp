#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int cnt[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date
{
	int year, month, day;

	date() {};

	date (string s)
		{
			day = (s[0] - '0') * 10 + s[1] - '0';
			month = (s[3] - '0') * 10 + s[4] - '0';
			year = (s[6] - '0') * 10 + s[7] - '0';
		}

	void operator ++()
		{
			day++;
			if (day > cnt[month - 1])
				{
					month++;
					day = 1;
				}

			if (month == 13)
				{
					month = 1;
					year++;
				}
		}

	bool operator != (date &a)
		{
			if (a.day == day && a.month == month && year == a.year)
				return false;

			return true;
		}
};

int main()
{	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;

	cin >> s;

	date d1(s);

	cin >> s;

	date d2(s);

	int ans = 0;

	for (; d1 != d2; ++d1)
		ans++;

	cout << ans;

	return 0;	
}
