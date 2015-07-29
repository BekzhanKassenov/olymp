/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <bitset>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all (x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T> 
inline T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

struct date {
 	int day, month, year;

 	bool leap;

 	bool is_leap() {
 		if (year % 400 == 0)
 			return true;

 	   	if (year % 100 == 0)
 	   		return false;

 	   	if (year % 4 == 0)
 	   		return true;

 	   	return false;	
 	}

 	date() : day(0), month(0), year(0), leap(false) {}

 	date(int day, int month, int year) : day(day), month(month), year(year) {
 		leap = is_leap();
 	}

 	int days_in_month() {
 		if (month == 2) 
 			return (28 + leap);

 		if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
 			return 31;

 		return 30;
 	}

 	void operator ++() {
 		day++;

 		if (day > days_in_month()) {
 			day = 1;
 			month++;
 		}

 		if (month > 12) {
 			month = 1;
 			year++;
 			leap = is_leap();
 		}
 	}

 	bool operator == (const date& a) const {
 		return ((year == a.year) && (month == a.month) && (day == a.day));
 	}

 	bool operator > (const date& a) const {
 		if (year > a.year)
 			return true;

 		if (year < a.year)
 			return false;

 		if (month > a.month)
 			return true;

 		if (month < a.month)
 			return false;

 		if (day > a.day)
 			return true;

 		return false;	
 	}
};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int year, day, month;

	char c1, c2;

	scanf("%d%c%d%c%d", &year, &c1, &month, &c2, &day);

	date start(day, month, year);

	scanf("%d%c%d%c%d", &year, &c1, &month, &c2, &day);

	date finish(day, month, year);

	int ans = 0;

	if (start > finish)
		swap(start, finish);

	while (!(start == finish)) {
		ans++;
		++start;
	}          

	cout << ans;

	return 0;
}
