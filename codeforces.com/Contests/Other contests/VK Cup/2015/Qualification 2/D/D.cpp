/****************************************
**      Solution by NU: Black Kex      **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum event_type {
    server_free,
    video_come
};

struct Event {
    event_type type;
    long long _time;
    int len;
    int num;

    bool operator < (const Event& event) const {
        if (_time != event._time) {
            return _time > event._time;
        }

        return type > event.type;
    }
};

int n, k;
int s, t;
long long ans[MAXN];
priority_queue <Event> pq;
queue <Event> q;
int cur_free;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    cur_free = k;

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &s, &t);
        Event event;
        event.type = video_come;
        event._time = s;
        event.len = t;
        event.num = i;
        pq.push(event);
    }

    while (!pq.empty()) {
        Event cur_event = pq.top();
        pq.pop();

        if (cur_event.type == server_free) {
            cur_free++;
        } else {
            q.push(cur_event);
        }

        while (!q.empty() && cur_free > 0) {
            Event temp = q.front();
            q.pop();

            Event event;
            event.type = server_free;
            event._time = cur_event._time + temp.len;
            event.len = 0;
            event.num = 0;

            ans[temp.num] = cur_event._time + temp.len;

            pq.push(event);
            cur_free--;
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%I64d\n", ans[i]);
    }

    return 0;
}
