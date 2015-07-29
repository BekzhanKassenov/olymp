#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

#define F first
#define S second
#define MP make_pair

struct _time {
    int h, m, s;

    _time() : h(0), m(0), s(0) { }

    _time(int h, int m, int s) : h(h), m(m), s(s) { }

    void read() {
        scanf("%d:%d:%d", &h, &m, &s);
    }

    void print() const {
        printf("%02d:%02d:%02d", h, m, s);
    }

    void advance(int sec) {
        int all_in_sec = h * 3600 + m * 60 + s + sec;
        h = all_in_sec / 3600;
        all_in_sec %= 3600;

        m = all_in_sec / 60;
        all_in_sec %= 60;

        s = all_in_sec;
    }

    bool operator < (const _time& _t) const {
        int all_in_sec = h * 3600 + m * 60 + s;
        int all_in_sec1 = _t.h * 3600 + _t.m * 60 + _t.s;

        return all_in_sec < all_in_sec1;
    }
};

int n, k, arr[110];
_time start[110], end[110];

void print_ans(const _time& st) {
    queue <pair <int, int> > q;

    int cur = 0;

    for (int i = 0; i < k; i++) {
        start[i] = st;
        start[i].advance(cur);
        
        if (arr[i] > 10) {
            q.push(MP(i, arr[i] - 10));
            cur += 10;
        } else {
            cur += arr[i];
            end[i] = st;
            end[i].advance(cur);
        }
    }

    while (!q.empty()) {
        pair <int, int> p = q.front();
        q.pop();

        if (p.S <= 10) {
            cur += p.S;
            end[p.F] = st;
            end[p.F].advance(cur);
        } else {
            p.S -= 10;
            q.push(p);
            cur += 10;
        }
    }

    for (int i = 0; i < k; i++) {
        start[i].print();
        printf(" ");
        end[i].print();
        printf("\n");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    _time temp;

    for (int i = 0; i < n / k; i++) {
        for (int j = 0; j < k; j++) {
            temp.read();
            scanf("%d", &arr[j]);
        }

        for (int j = 0; j < k; j++)
            if (temp < end[j])
                temp = end[j];

        print_ans(temp);
    }

    return 0;
}
