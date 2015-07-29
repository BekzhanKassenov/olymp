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
			year = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + s[9] - '0';
		}

	date (int year, int month, int day) : year(year), month(month), day(day) {}

	void operator ++()
		{
			day++;

			if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && day == 29 && month == 2)
				return;

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

	int ans = 1;

	while (d1 != d2)
		{
			ans++;
			++d1;
		}

	cout << ans;

	return 0;
}
