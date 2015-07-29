#include <iostream>
#include <cstdio>

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

	date (int year, int month, int day) : year(year), month(month), day(day) {}

	void operator ++()
		{
			day++;

			if (year == 2008 && day == 29 && month == 2)
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

	int n;

	cin >> n;

	date d(2008, 1, 1);

	int day = 2;

	for (int i = 0; i < n; i++)
		{
			++d;
			++day;
			if (day > 7)
				day = 1;
		}

	switch (day)
		{
			case 1:
				cout << "Monday, ";
				break;
			case 2: 
				cout << "Tuesday, ";
				break;
			case 3:
				cout << "Wednesday, ";
				break;
			case 4: 
				cout << "Thursday, ";
				break;
			case 5:
				cout << "Friday, ";
				break;
			case 6:
				cout << "Saturday, ";
				break;
			case 7:
				cout << "Sunday, ";
		}

	if (d.day < 10)
		cout << 0;

	cout << d.day << '.';

	if (d.month < 10)
		cout << 0;

	cout << d.month;

	return 0;
}
