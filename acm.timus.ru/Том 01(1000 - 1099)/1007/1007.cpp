#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

const int MAXN = 1010;

int n;
char s[MAXN];

void add(char s[], int sum, int cnt) {
    int pos = -1;
    char num = 0;

    if (sum % (n + 1) == 0) {
        pos = n - 1;
        num = '0';
    }

    for (int i = 0; i <= n - 1; i++) {
        if ((sum + cnt) % (n + 1) == 0) {
            pos = i;
            num = '0';
            break;
        }

        if ((sum + cnt + i + 1) % (n + 1) == 0) {
            pos = i;
            num = '1';
            break;
        }

        if (s[i] == '1') {
            cnt--;
        }
    }

    for (int i = n; i > pos; i--) {
        s[i] = s[i - 1];
    }

    s[pos] = num;
    s[n] = '\0';
}

void remove(char s[], int sum, int cnt) {
    int pos = -1;
    for (int i = 0; i < n + 1; i++) {
        if (s[i] == '1') {
            cnt--;
        }

        int temp = sum;

        if (s[i] == '1') {
            temp -= i + 1;
        }

        temp -= cnt;

        temp %= n + 1;
        temp += n + 1;

        if (temp % (n + 1) == 0) {
            pos = i;
            break;
        } 
    }

    assert(pos != -1);

    for (int i = pos; i < n; i++) {
        s[i] = s[i + 1];
    }

    s[n] = '\0';
}

void change(char s[], int sum) {
    if (sum % (n + 1) == 0) {
        return;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if ((sum - (i + 1)) % (n + 1) == 0) {
                s[i] = '0';
                return;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);

    while (scanf("%s", s) == 1) {
        int sum = 0, cnt = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '1') {
                sum += i + 1;
                cnt++;
            }
        }

        if (cnt == 0) {
            for (int i = 0; i < n; i++) {
                putchar('0');
            }
            putchar('\n');
            continue;
        }

        int len = strlen(s);

        if (len == n - 1) {
            add(s, sum, cnt);
        } else if (len == n) {
            change(s, sum);
        } else if (len == n + 1) {
            remove(s, sum, cnt);
        } else {
            assert(false);
        }

        puts(s);
    }

    return 0;
}
