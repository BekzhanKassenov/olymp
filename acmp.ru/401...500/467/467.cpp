#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 510;
const int INF = (int)1e9;

#define all(x) (x).begin(), (x).end()

struct Interval {
    int l, r;
    bool color;

    Interval() { }

    Interval(int l, int r, bool color) : l(l), r(r), color(color) { }

    bool in(int left, int right) {
        return left <= l && r <= right;
    }
};

vector <Interval> vec;
vector <int> temp;
int n;
int l[MAXN], r[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    temp.push_back(0);
    temp.push_back(INF - 1);

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l[i], &r[i]);
        r[i]--;
        temp.push_back(r[i]);
        temp.push_back(l[i]);
    }

    sort(all(temp));
    temp.resize(unique(all(temp)) - temp.begin());

    for (size_t i = 0; i + 1 < temp.size(); i++) {
        vec.push_back(Interval(temp[i], temp[i], true));
        
        if (temp[i] + 2 <= temp[i + 1]) {
            vec.push_back(Interval(temp[i] + 1, temp[i + 1] - 1, true));
        }
    }

    vec.push_back(Interval(temp.back(), temp.back(), true));

    for (int i = 0; i < n; i++) {
        for (size_t j = 0; j < vec.size(); j++) {
            if (vec[j].in(l[i], r[i])) {
                vec[j].color ^= true;
            }
        }
    }

    int len = 0;
    int ans = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i].color) {
            len += vec[i].r - vec[i].l + 1;
        } else {
            len = 0;
        }

        ans = max(ans, len);
    }

    printf("%d\n", ans);

    return 0;
}