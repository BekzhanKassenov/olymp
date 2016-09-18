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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

map <string, int> nameToNum;
string numToName[MAXN];

int getNum(const string& s) {
    if (!nameToNum.count(s)) {
        int pos = nameToNum.size();
        nameToNum[s] = pos;
        numToName[pos] = s;
    }

    return nameToNum[s];
}

int T;
vector <int> g[MAXN];
bool used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
#ifdef Local
    freopen("in", "r", stdin);
#endif

    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        nameToNum.clear();
        for (int i = 0; i < n; i++) {
            g[i].clear();
            used[i] = false;
        }

        for (int q = 0; q < n; q++) {
            string name;
            cin >> name;
            int num = getNum(name);
            int len;
            cin >> len;

            for (int i = 0; i < len; i++) {
                string dep;
                cin >> dep;
                g[num].push_back(getNum(dep));
            }
        }

        queue <int> q;
        for (int i = 0; i < k; i++) {
            string name;
            cin >> name;
            int num = getNum(name);
            q.push(num);
            used[num] = true;
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            for (int to: g[v]) {
                if (!used[to]) {
                    q.push(to);
                    used[to] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (used[i]) {
                cout << numToName[i] << endl;
            }
        }
    }
    
    return 0;
}
