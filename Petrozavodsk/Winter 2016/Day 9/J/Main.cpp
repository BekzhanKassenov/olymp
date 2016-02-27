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
const int MAXN = 7000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

pair <int, int> arr[MAXN];
bool dp[100][100][100];
bool par[100][100][100];

vector <int> calc(const vector <pair <int, int> >& vec, int num) {
    int n = vec.size();

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < num; k++) {
                dp[i][j][k] = false;
                par[i][j][k] = false;
            }
        }
    }

    dp[0][0][0] = true;

    for (int i = 0; i < n; i++) {
        for (int cnt = 0; cnt <= n; cnt++) {
            for (int m = 0; m < num; m++) {
                if (!dp[i][cnt][m]) {
                    continue;
                }

                dp[i + 1][cnt][m] = true;
                dp[i + 1][cnt + 1][(m + vec[i].first) % num] = true;

                par[i + 1][cnt][m] = false;
                par[i + 1][cnt + 1][(m + vec[i].first) % num] = true;
            }
        }
    }

    int m = 0, cnt = num;

    vector <int> res;
    for (int i = n; i > 0 && cnt; i--) {
        if (par[i][cnt][m]) {
            res.push_back(vec[i - 1].second);
            m = (m - vec[i - 1].first % num + num) % num;
            cnt--;
        }
    }
    
    return res;
}

int n = 6666, mod;

vector <int> block32[200];
vector <int> block9[20];
vector <int> block7;

int sum32[200];
int sum9[20];
int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }

    {
        deque <pair <int, int> > deq32(arr, arr + n);
        
        vector <pair <int, int> > temp;
        for (int i = 0; i < 170; i++) {
            temp.clear();
            for (int j = 0; j < 70 && !deq32.empty(); j++) {
                temp.push_back(deq32.front());
                deq32.pop_front();
            }

            vector <int> indices(calc(temp, 32));

            for (int idx: indices) {
                block32[i].push_back(idx);
                sum32[i] += arr[idx].first;
            }

            sort(all(indices));

            for (const auto& p: temp) {
                if (!binary_search(all(indices), p.second)) {
                    deq32.push_front(p);
                }
            }   
        }
    }

    {
        deque <pair <int, int> > deq9;
        for (int i = 0; i < 170; i++) {
            int S = sum32[i];
            deq9.emplace_back(S, i);
        }

        for (int i = 0; i < 16; i++) {
            vector <pair <int, int> > temp;
            for (int j = 0; j < 20; j++) {
                temp.push_back(deq9.front());
                deq9.pop_front();
            }

            vector <int> indices(calc(temp, 9));

            for (int idx: indices) {
                block9[i].push_back(idx);
                sum9[i] += sum32[idx];
            }

            sort(all(indices));

            for (const auto& p: temp) {
                if (!binary_search(all(indices), p.second)) {
                    deq9.push_front(p);
                }
            }   
        }
    }
    
    {
        deque <pair <int, int> > deq7;
        for (int i = 0; i < 16; i++) {
            int S = sum9[i];
            deq7.emplace_back(S, i);
        }

        vector <pair <int, int> > temp;
        for (int j = 0; j < 14; j++) {
            temp.push_back(deq7.front());
            deq7.pop_front();
        }

        vector <int> indices(calc(temp, 7));

        for (int idx: indices) {
            block7.push_back(idx);
        }
    }

    int cnt = 0;
    int S = 0;
    set <int> Set;
    for (int idx: block7) {
        for (int idx1: block9[idx]) {
            for (int idx2: block32[idx1]) {
                cnt++;
                printf("%d\n", idx2 + 1);
                S += arr[idx2].first;
                S %= 2016;

                Set.insert(idx2);
            }
        }
    }

#ifdef Local
    cout << "Total count: " << cnt << endl;
    cout << "Module: " << S << endl;
    cout << "Set size: " << Set.size() << endl;

    if (S != 0 || Set.size() != 2016) {
        return 1;
    }
#endif
    
    return 0;
}
