#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

char s[100];

const char* names[] = {"mile",
                       "km",
                       "m",
                       "uin",
                       "kairi",
                       "zhang",
                       "sen"
                      };

const int values[] = {1609, 1000, 1, 33, 1852, 3, 38};

int read() {
    gets(s);

    int pos = 0;
    int res = 0;

    while (s[pos] >= '0' && s[pos] <= '9') {
        res *= 10;
        res += s[pos] - '0';
        pos++;
    }

    for (int i = 0; i < 7; i++) {
        if (strcmp(s + pos, names[i]) == 0) {
            res *= values[i];
        }
    }

    return res;
}

int n, ansa, ansb, ansc;
pair <int, int> a[100010];
double ans;

double area(int a, int b, int c) {
    double p = (a + b + c) / 2.0;

    return p * (p - a) * (p - b) * (p - c);
}

int main() {    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        a[i].first = read();
        a[i].second = i + 1;
    }

    sort(a, a + n);

    for (int i = 1; i < n; i++) {
        int sum = a[i].first + a[i - 1].first;

        int pos = lower_bound(a, a + n, make_pair(sum, 0)) - a - 1;

        if (pos > i && pos < n && sum > a[pos].first) {
            double A = area(a[i].first, a[i - 1].first, a[pos].first);

            if (A > ans) {
                ans = A;
                ansa = a[i].second;
                ansb = a[i - 1].second;
                ansc = a[pos].second; 
            }
        }
    }

    printf("%10lf\n%d %d %d", sqrt(ans) / 4.0, ansa, ansb, ansc);

    return 0;
}