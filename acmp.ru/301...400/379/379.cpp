#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int win[500];

struct Date {
    int day, month;

    Date() { }

    Date(const Date& d) : day(d.day), month(d.month) { }

    bool is_date() const {
        if (month < 1 || month > 12)
            return false;

        return day > 0 && day <= days[month];
    }

    bool is_end() const {
        return month == 12 && day == 31;
    }

    int position() const {
        int res = 0;

        for (int i = 0; i < month; i++)
            res += days[i];

        res += day;

        return res;
    }

    int read() {
        return scanf("%d %d\n", &day, &month);
    }
};

bool win_day(const Date& d) {
    int pos = d.position();

    if (d.is_end())
        return true;

    if (win[pos] != -1)
        return win[pos];
    
    Date temp(d);
    int& res = win[pos];
    res = false;;

    for (int i = 0; i < 2; i++) {
        temp.day++;

        if (temp.is_date()) 
            res |= !win_day(temp);
    }

    temp = d;
    
    for (int i = 0; i < 2; i++) {
        temp.month++;

        if (temp.is_date())
            res |= !win_day(temp);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Date d;
    d.read();
    memset(win, 255, sizeof win);

    printf("%d\n", 1 + !win_day(d));

    return 0;
}