#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

#define F first
#define S second

struct jul_date {
    int year, month, day;

    jul_date() { }

    jul_date(int year, int month, int day) : year(year), month(month), day(day) { }

    bool is_leap() {
        return (year % 4 == 0);
    }

    int days_in_month() {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            return 31;

        if (month == 2) {
            if (is_leap())
                return 29;
            return 28;
        }

        return 30;
    }

    void operator ++ () {
        day++;

        if (day > days_in_month()) {
            day = 1;
            month++;

            if (month == 13) {
                year++;
                month = 1;
            }
        }
    }

    bool operator != (const jul_date& d) const {
        return (year != d.year || month != d.month || day != d.day);
    }

    bool operator < (const jul_date& d) const {
        if (year != d.year)
            return year < d.year;

        if (month != d.month)
            return month < d.month;

        return day < d.day; 
    }
};


struct greg_date {
    int year, month, day;

    greg_date() { }

    greg_date(int year, int month, int day) : year(year), month(month), day(day) { }

    bool is_leap() {
        if ((year % 100 == 0 && year % 400 != 0))
            return false;

        return (year % 4 == 0); 
    }

    int days_in_month() {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            return 31;

        if (month == 2) {
            if (is_leap())
                return 29;

            return 28;
        }

        return 30;
    }

    void print() {
        printf("%04d-%02d-%02d\n", year, month, day);
    }

    void operator ++ () {
        day++;

        if (day > days_in_month()) {
            day = 1;
            month++;

            if (month == 13) {
                year++;
                month = 1;
            }
        }
    }

};

map <jul_date, greg_date> Map;

int main() {
    #ifdef Local
        freopen("in", "r", stdin);
    #endif

    jul_date end(9999, 11, 18);

    jul_date cur(1582, 10, 4);

    greg_date res(1582, 10, 15);

    while (cur != end) {
        Map[cur] = res;
        ++cur;
        ++res;
    }

    int year, month, day;

    while (scanf("%d-%d-%d", &year, &month, & day) == 3) {
        res = Map[jul_date(year, month, day)];

        res.print();
    }

    return 0;
}
