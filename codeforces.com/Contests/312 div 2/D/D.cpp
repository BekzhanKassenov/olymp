/****************************************
**     Solution by Bekzhan Kassenov    **
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
typedef pair <long long, long long> Segment;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const Segment BAD = make_pair(-1, -1);

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum TYPE {
    OPEN,
    CLOSE
};

long long LEFT, RIGHT;
int h, q;

void get_union(vector <Segment>& vec) {
    vector <pair <long long, TYPE> > event;

    for (size_t i = 0; i < vec.size(); i++) {
        event.push_back(make_pair(vec[i].first, OPEN));
        event.push_back(make_pair(vec[i].second, CLOSE));
    }

    sort(all(event));
    vec.clear();
    int cnt = 0;
    long long open = -1;

    for (size_t i = 0; i < event.size(); i++) {
        if (event[i].second == OPEN) {
            cnt++;
            if (cnt == 1) {
                open = event[i].first;
            }
        } else {
            cnt--;
            if (cnt == 0) {
                vec.push_back(make_pair(open, event[i].first));
            }
        }
    }
}

Segment get_intersection(const Segment& a, const Segment& b) {
    if (a == BAD || b == BAD || a.second < b.first || b.second < a.first) {
        return BAD;
    }

    return make_pair(max(a.first, b.first), min(a.second, b.second));
}

vector <Segment> invert(const vector <Segment>& vec) {
    vector <Segment> result;

    if (vec.empty()) {
        result.push_back(make_pair(LEFT, RIGHT));
        return result;
    }

    if (vec[0].first > LEFT) {
        result.push_back(make_pair(LEFT, vec[0].first - 1));
    }

    for (size_t i = 0; i + 1 < vec.size(); i++) {
        long long left_ = vec[i].second + 1;
        long long right_ = vec[i + 1].first - 1;

        if (left_ <= right_) {
            result.push_back(make_pair(left_, right_));
        }
    }

    if (vec.back().second + 1 <= RIGHT) {
        result.push_back(make_pair(vec.back().second + 1, RIGHT));
    }
    
    return result;
}

int lev, reply;
long long left_, right_;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &h, &q);

    LEFT = 1ll << (h - 1);
    RIGHT = (1ll << h) - 1;

    vector <Segment> in, not_in;

    while (q--) {
        scanf("%d%I64d%I64d%d", &lev, &left_, &right_, &reply);

        int diff = h - lev;

        if (diff != 0) {
            left_ <<= diff;
            
            right_ <<= diff;
            right_ |= (1ll << diff) - 1;
        }

        if (reply == 1) {
            in.push_back(make_pair(left_, right_));
        } else {
            not_in.push_back(make_pair(left_, right_));
        }
    }

    vector <Segment> answer;
    Segment inter = make_pair(LEFT, RIGHT);

    for (size_t i = 0; i < in.size(); i++) {
        inter = get_intersection(inter, in[i]);
    }

    if (inter == BAD) {
        puts("Game cheated!");
        return 0;
    }
    
    get_union(not_in);
    not_in = invert(not_in);

    for (size_t i = 0; i < not_in.size(); i++) {
        Segment temp = get_intersection(inter, not_in[i]);

        if (temp != BAD) {
            answer.push_back(temp);
        }
    }

    if (answer.empty()) {
        puts("Game cheated!");
    } else if (answer.size() > 1u || answer[0].second > answer[0].first) {
        puts("Data not sufficient!");
    } else {
        printf("%I64d\n", answer[0].first);
    }
    
    return 0;
}
