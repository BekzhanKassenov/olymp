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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
map <string, vector <pair <int, int> > > Map;

bool conflict(vector <pair <int, int> >& vec) {
    sort(all(vec));

    for (size_t i = 0; i + 1 < vec.size(); i++) {
        if (vec[i].second >= vec[i + 1].first) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);

#ifdef Local
    freopen("in", "r", stdin);
#endif

    cin >> T;

    while (T--) {
        Map.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;

            pair <int, int> tim;
            cin >> tim.first >> tim.second;

            int k;
            cin >> k;

            for (int j = 0; j < k; j++) {
                string vol;
                cin >> vol;
                Map[vol].push_back(tim);
            }
        }

        vector <string> ans;
        for (auto& p : Map) {
            if (conflict(p.second)) {
                ans.push_back(p.first);
            }
        }

        cout << ans.size() << endl;
        for (const auto& s : ans) {
            cout << s << endl;
        }
    }
    
    return 0;
}
