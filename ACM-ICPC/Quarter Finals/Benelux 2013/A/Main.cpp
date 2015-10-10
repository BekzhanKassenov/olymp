/****************************************
**          Solution by NU #2          **
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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, m;

// Car
map <string, int> cpos;
string name[MAXN];
int cat_price[MAXN], pickup[MAXN], perkm[MAXN];

// Spy
map <string, int> spos;
int car[MAXN];
long long bill[MAXN];


// Event
int t;
string sname, cname;
char type;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    cin >> T;
    
    while (T--) {
        cpos.clear();
        spos.clear();

        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            cin >> name[i] >> cat_price[i] >> pickup[i] >> perkm[i];
            cpos[name[i]] = i;
        }

        for (int i = 0; i < 510; i++) {
            bill[i] = 0;
            car[i] = -1;
        }

        for (int i = 0; i < m; i++) {
            cin >> t >> sname >> type;

            if (!spos.count(sname)) {
                int num = spos.size();
                spos[sname] = num;
            }

            int spy = spos[sname];

            if (type == 'p') {
                cin >> cname;

                int carpos = cpos[cname];

                if (bill[spy] == -1) {
                    continue;
                }

                if (car[spy] != -1) {
                    bill[spy] = -1;
                } else {
                    bill[spy] += pickup[carpos];
                    car[spy] = carpos;
                }

            } else if (type == 'r') {
                int dist;
                cin >> dist;
                
                if (bill[spy] == -1) {
                    continue;
                }
                
                if (car[spy] == -1) {
                    bill[spy] = -1;
                } else {
                    int carpos = car[spy];
                    bill[spy] += dist * perkm[carpos];
                    
                    car[spy] = -1;
                }
            } else {
                int severity;
                cin >> severity;
                
                if (bill[spy] == -1) {
                    continue;
                }
                
                if (car[spy] == -1) {
                    bill[spy] = -1;
                } else {
                    int carpos = car[spy];

                    bill[spy] += ceil((severity * cat_price[carpos]) / 100.0);
                }
            }
        }

        for (size_t i = 0; i < spos.size(); i++) {
            if (car[i] != -1) {
                bill[i] = -1;
            }
        }

        for (auto it: spos) {
            cout << it.first << ' ';
            if (bill[it.second] == -1) {
                cout << "INCONSISTENT" << endl;
            } else {
                cout << bill[it.second] << endl;
            }
        }
        cerr << endl;
    }

    return 0;
}