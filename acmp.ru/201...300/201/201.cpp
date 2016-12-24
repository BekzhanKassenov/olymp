#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 110;

int read() {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}

void print(int _time) {
    int h = _time / 3600;
    _time %= 3600;
    h %= 24;

    int m = _time / 60;
    _time %= 60;

    int s = _time;

    printf("%02d:%02d:%02d", h, m, s);
}

int n, k;
int dur[MAXN];
int start[MAXN], _end[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    queue <int> q;
    int cur = 0;

    auto process = [&cur, &q](int i) {
        if (dur[i] <= 10) {
            cur += dur[i];
            _end[i] = cur;
        } else {
            cur += 10;
            dur[i] -= 10;
            q.push(i);
        }
    };

    for (int i = 0; i < n / k; i++) {
        for (int j = 0; j < k; j++) {
            start[j] = read();
            if (start[j] > cur) {
                cur = start[j];
            }
            scanf("%d", &dur[j]);
        }

        for (int i = 0; i < k; i++) {
            start[i] = cur;
            process(i);
        }

        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            process(idx);
        }

        for (int i = 0; i < k; i++) {
            print(start[i]);
            putchar(' ');
            print(_end[i]);
            putchar('\n');
        }
    }

    return 0;
}
