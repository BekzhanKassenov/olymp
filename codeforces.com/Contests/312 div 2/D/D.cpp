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

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const pair <long long, long long> BAD = make_pair(-1, -1);

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

void get_union(vector <pair <long long, long long> >& vec) {
    vector <pair <int, TYPE> > event;

    for (size_t i = 0; i < vec.size(); i++) {
        event.push_back(make_pair(vec[i].first, OPEN));
        event.push_back(make_pair(vec[i].second, CLOSE));
    }

    sort(all(event));
    vec.clear();
    int cnt = 0;
    int open = -1;

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

pair <long long, long long> get_intersection(const pair <long long, long long>& a, const pair <long long, long long>& b) {
    if (a == BAD || b == BAD || a.second < b.first || b.second < a.first) {
        return BAD;
    }

    return make_pair(max(a.first, b.first), min(a.second, b.second));
}

pair <long long, long long> get_intersection(vector <pair <long long, long long> >& vec) {
    pair <long long, long long> result = vec[0];

    for (size_t i = 1; i < vec.size(); i++) {
        result = get_intersection(result, vec[i]);
    }

    return result;
}

vector <pair <long long, long long> > invert(const vector <pair <long long, long long> >& vec) {
    vector <pair <long long, long long> > result;

    if (vec.empty()) {
        result.push_back(make_pair(LEFT, RIGHT));
        return result;
    }

    if (vec[0].first != LEFT) {
        result.push_back(make_pair(LEFT, vec[0].first - 1));
    }

    for (size_t i = 0; i + 1 < vec.size(); i++) {
        long long left_ = vec[i].second + 1;
        long long right_ = vec[i + 1].first - 1;

        if (left_ < right_) {
            result.push_back(make_pair(left_, right_));
        }
    }

    if (vec.back().second + 1 <= RIGHT) {
        result.push_back(make_pair(vec.back().second + 1, RIGHT));
    }
    
    return result;
}

vector <pair <long long, long long> > solve(vector <pair <long long, long long> >& in, vector <pair <long long, long long> >& not_in) {
    pair <long long, long long> inter;

    if (in.empty()) {
        inter = make_pair(LEFT, RIGHT);
    } else {
        inter = get_intersection(in);
    }

    if (inter == BAD) {
        vector <pair <long long, long long> > vec;
        return vec;
    }

    get_union(not_in);
    
    not_in = invert(not_in);

    vector <pair <long long, long long> > answer;

    for (size_t i = 0; i < not_in.size(); i++) {
        pair <long long, long long> temp = get_intersection(inter, not_in[i]);

        if (temp != BAD) {
            answer.push_back(temp);
        }
    }

    return answer;
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

    vector <pair <long long, long long> > good, bad;

    while (q--) {
        scanf("%d%I64d%I64d%d", &lev, &left_, &right_, &reply);

        int diff = h - lev;

        if (diff != 0) {
            left_ <<= diff;
            
            right_ <<= diff;
            right_ |= (1ll << diff) - 1;
        }

        if (reply == 1) {
            good.push_back(make_pair(left_, right_));
        } else {
            bad.push_back(make_pair(left_, right_));
        }
    }

    vector <pair <long long, long long> > ans = solve(good, bad);

    if (ans.empty()) {
        puts("Game cheated!");
    } else if (ans.size() > 1u || ans[0].second > ans[0].first) {
        puts("Data not sufficient!");
    } else {
        printf("%I64d\n", ans[0].first);
    }
    
    return 0;
}
