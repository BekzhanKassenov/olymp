/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct City {
    string name;
    string free_at[24];

    void read() {
        cin >> name;
        int cnum;
        cin >> cnum;

        for (int i = 0; i < cnum; i++) {
            string mask, name;
            cin >> mask >> name;

            for (int j = 0; j < 24; j++) {
                if (free_at[j].empty() && mask[j] == '.') {
                    free_at[j] = name;
                }
            }
        }
    }
};

map <string, int> pos;
City city[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
#ifdef Local
    freopen("in", "r", stdin);
#endif

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        city[i].read();
        pos[city[i].name] = i;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector <int> vec(k);
        for (int j = 0; j < k; j++) {
            string name;
            cin >> name;
            vec[j] = pos[name];
        }

        int hr = -1;
        for (int h = 0; h < 24; h++) {
            bool good = true;
            for (int j = 0; j < k; j++) {
                if (city[vec[j]].free_at[h].empty()) {
                    good = false;
                    break;
                }
            }

            if (good) {
                hr = h;
                break;
            }
        }

        if (hr != -1) {
            cout << "Yes";
            for (int j = 0; j < k; j++) {
                cout << ' ' << city[vec[j]].free_at[hr];
            }
            cout << endl;
        } else {
            cout << "No" << endl;
        }
    }

    
    return 0;
}
