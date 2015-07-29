#include <iostream>
#include <cstdio>

using namespace std;

int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date {
    int month, day;
    int week_day;
    int past_holydays;
    
    date() : month(1), day(0), week_day(0), past_holydays(0) { }
    
    bool operator == (const date& rhs) const {
        return (month == rhs.month && day == rhs.day);
    }
    
    void operator ++ (int) {
        day++;
        
        if (day > month_days[month]) {
            day = 1;
            month++;
        }    
    
        week_day++;
        week_day %= 7;
    
        if (week_day > 4)
            past_holydays++;
    }
};

ostream& operator << (ostream& c, const date& d) {
    c << d.day << '.' << d.month;
    return c;
}

date man, woman;

int make(int week_day, int cnt) {
    date d;
    d.week_day = week_day;
    
    int res = 0;
    
    while (cnt > 0) {
        for (int i = 0; i < cnt; i++) {
            d++;
            
            //cout << d << endl;
            
            if (d == man || d == woman)
                d.past_holydays++;
                
            res++;    
        }
        
        cnt = d.past_holydays;
        d.past_holydays = 0;
        
        if (cnt == 0 && d.week_day == 4) {
            cnt = 2;
            d.past_holydays = -2;
        } else if (cnt == 0 && (d.day == 22 && d.month == 2 || d.day == 7 && d.month == 3)) {
            cnt = 1;
            d.past_holydays = -1;
        }
    }
    
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    man.day = 23;
    man.month = 2;
    
    woman.day = 8;
    woman.month = 3;
    
    int n;
    cin >> n;
    
    int ans = 3;
    
    for (int i = 0; i < 7; i++)
        ans = max(ans, make(i, n));
        
    cout << ans;
    
    return 0;
}

