#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;

bool bad_month[maxn], bad_week[maxn];
int month_size, olymp_size;
int week_size, first_day, temp, x;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &month_size, &olymp_size);

    scanf("%d%d%d", &week_size, &temp, &first_day);

    for (int i = 0; i < temp; i++) {
        scanf("%d", &x);
        bad_week[--x] = true;
    }

    scanf("%d", &temp);

    for (int i = 0; i < temp; i++) {
        scanf("%d", &x);
        bad_month[--x] = true;
    }

    first_day--;

    for (int i = 0; i < month_size; i++) {
        bad_month[i] |= bad_week[first_day];
        first_day++;
        first_day %= week_size;
    }

    int ans = 0, cnt = 0;

    for (int i = 0; i < month_size; i++) {
        if (bad_month[i]) {
            ans += max(0, cnt - olymp_size + 1);
            cnt = 0;
        } else {
            cnt++;
        }
    }

    ans += max(0, cnt - olymp_size + 1);

    printf("%d", ans);

    return 0;
}
