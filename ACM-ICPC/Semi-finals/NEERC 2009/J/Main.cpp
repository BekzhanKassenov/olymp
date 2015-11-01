/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "javacert"

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

int get_round(int x, int y) {
    if (200 * (y - x) % y == 0 && ((200 * (y - x) / y) % 2 == 1) ) {
        int temp = 200 * (y - x) / y;
        if (temp%4 == 1) {
            return int(100.0 * (y - x) / y);
        }
        if (temp%4 == 3) {
            return int(100.0 * (y - x) / y + 1.0);
        }        
        assert(false);
    }

    return int(100.0 * (y - x) / y + 0.5);
}

vector<pair<int, int> > get_ratio(int x) {
    vector<pair<int, int> > answer;
    for (int i = 0; i <= 100; i++) {
        for (int j = max(i, 1); j <= 100; j++) {
            if (x == get_round(i, j)) {
                answer.push_back(make_pair(i, j));
            }    
        }
    }    
    assert(answer.size() != 0);

    return answer;
}

vector<pair<int, int> > v[12];
pair<int, int> dp[102][102][12];
pair<int, int> p[102][102][12];
int k, n, m;

void print(int x, int y, int z) {
    if (z != 0) {
        print(x + p[x][y][z].first, y + p[x][y][z].second, z - 1);
    }

    cout << p[x][y][z].first << " " << p[x][y][z].second << endl;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    cin >> k >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        v[i] = get_ratio(x);

    }

    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            for (int q = 0; q < 12; q++) {
                dp[i][j][q] = make_pair(-1, -1);
            }
        }
    }

    dp[k][n][0] = make_pair(INF, 0);

    for (int i = 1; i <= m; i++) {
        for (int q = 0; q < 101; q++) {
            for (int t = 0; t <= q; t++) {
                int f = dp[t][q][i - 1].first;
                int s = dp[t][q][i - 1].second;
                if (f != -1) {
                    for (size_t j = 0; j < v[i].size(); j++) {
                        pair<int, int> pt = v[i][j];
                        if (t + pt.first < 101 && q + pt.second < 101) {
                            pair<int, int> temp = dp[t + pt.first][q + pt.second][i];
                            pair<int, int> ans_temp = make_pair(min(temp.first, pt.second), max(temp.second, pt.second));
                            if (temp.first == -1) {
                                dp[t + pt.first][q + pt.second][i] = ans_temp;
                                p[t + pt.first][q + pt.second][i] = v[i][j];                            
                            }
                            else {
                                if (temp.second - temp.first > ans_temp.second - ans_temp.first) {
                                    dp[t + pt.first][q + pt.second][i] = ans_temp;
                                    p[t + pt.first][q + pt.second][i] = v[i][j];
                                }
                            }
                        }         
                    }
                }
            }        
        }        
    }
    for (int q = 0; q < 12; q++) {
        cout << "q: " << q << endl;
        for (int i = 0; i < 102; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i][j][q].first != -1) {
                    printf("(%d %d) ", i, j);
                }
            }
        }
        cout << endl;
    }
    for (int q = 0; q < 12; q++) {
        cout << "q: " << q << endl;
        for (int i = 0; i < 102; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i][j][q].first != -1) {
                    cout << 1;
                }
            }
        }
        cout << endl;
    }
    print(0, 0, m);
    return 0;
}


/*
            for (int t = 0; t < 101; t++) {
                for (int q = 0; q <= t; q++) {
                    int f = v[i][j].first, s = v[i][j].second;    
                    if (q + f < 101 && t + s < 101) {
                        pair<int, int> pt = dp[q + f][t + s][i - 1];
                        if (pt.first != -1) {

                            pair<int, int> temp_ans = make_pair(min(s, pt.first), max(s, pt.second));
                            if (dp[q][t][i].first == -1) {
                                dp[q][t][i] = temp_ans;
                                p[q][t][i] = v[i][j];
                            }                                    
                            else {
                                if (temp_ans.second - temp_ans.first < dp[q][t][i].second - dp[q][t][i].first) {
                                    dp[q][t][i] = temp_ans;
                                    p[q][t][i] = v[i][j];                                
                                }
                            }
                        }
                    }
                }
            }
            */