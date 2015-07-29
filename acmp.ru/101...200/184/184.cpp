#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int sum[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
int cnt[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct date {
 	int month, day, hour, minute;
 	
 	date() {}

 	bool operator < (const date& d) const {
 		if (month < d.month)
 			return true;

 		if (month > d.month)
 			return false;

 		if (day < d.day)
 			return true;

 		if (day > d.day)
 			return false;

 		if (hour < d.hour)
 			return true;

 		if (hour > d.hour)
 			return false;

 		return (minute < d.minute);	
 	}

 	bool operator != (const date& d) const {
 		return (month != d.month || day != d.day || hour != d.hour || minute != d.minute);
 	}
};

ostream& operator << (ostream& c, const date& d) {
	c << d.day << ' ' << d.month << ' ' << d.hour << ' ' << d.minute;
	return c;
}

void inc(date& d) {
	d.minute++;

	if (d.minute == 60) {
		d.minute = 0;
		d.hour++;
		if (d.hour == 18) {
			d.hour = 10;
			d.day++;
			if (d.day > cnt[d.month - 1]) {
				d.day = 1;
				d.month++;
			}
		}
	}
}

int operator - (const date& d, const date& a) {
 	date temp = a;

 	int res = 0;

 	while (temp != d) {
 		//cout << temp << endl;
 	 	inc(temp);
 	 	res++;
 	}

 	return res + 1;
}

istream& operator >> (istream& c, date &d) {
 	char ch;
 	c >> d.day >> ch;
 	c >> d.month >> ch;
 	c >> d.hour >> ch;
 	c >> d.minute;
	return c;
}

int main() {
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);

  	int n;

  	cin >> n;

  	vector <date> a(n);

  	for (int i = 0; i < n; i++)
  		cin >> a[i];

  	sort(a.begin(), a.end());

  	int ans = 0;

	for (int i = 1; i < n; i += 2)
		ans += a[i] - a[i - 1];

	int rem = ans % 60;
	cout << ans / 60 << ':';
	if (rem < 10)
		cout << 0;
	cout << rem;	
	return 0;
}