/****************************************
**          Solution by NU #2          **
****************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

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
const int MAXDP = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, r, m;
int v[15], c[15];
int ans[10];
long long dp[22][MAXDP];
int faces[22];
vector <int> labels[22];
vector <long long> result;
map <long long, vector <long long> > Map;
bool found = false;

ostream& operator << (ostream& out, const vector <long long>& vec) {
    out << '{';
    for (size_t i = 0; i + 1 < vec.size(); i++) {
        out << vec[i] << ", ";
    }

    out << vec.back() << '}';
    return out;
}

template <typename T>
bool cmp(const vector <T>& a, const vector <T>& b) {
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }

    return false;
}

long long hash(const vector <long long>& vec) {
    long long result = 0;

    for (size_t i = 0; i < vec.size(); i++) {
        result *= 51;
        result += vec[i];
    }

    return result;
}

void add(vector <long long>& vec, int label, int mul) {
    for (int j = 0; j < m; j++) {
        if (0 <= v[j] - label && v[j] - label < MAXDP) {
            vec[j] += 1ll * mul * dp[n - 1][v[j] - label];
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    int cnt = 0;
    for (scanf("%d", &n); n != 0; scanf("%d", &n)) {
        cnt++;
        Map.clear();
        found = false;

        for (int i = 0; i < n; i++) {
            scanf("%d", &faces[i]);
            labels[i].resize(faces[i]);

            for (int j = 0; j < faces[i]; j++) {
                scanf("%d", &labels[i][j]);
            }

            for (int sum = 0; sum < MAXDP; sum++) {
                dp[i][sum] = 0;
            }
        }

        scanf("%d%d", &r, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &v[i], &c[i]);
        }

        result.assign(r, 51);
        for (int i = 0; i < faces[0]; i++) {
            dp[0][labels[0][i]]++;
        }

        for (int pos = 1; pos < n; pos++) {
            for (int sum = 0; sum < MAXDP; sum++) {
                for (int i = 0; i < faces[pos]; i++) {
                    if (sum - labels[pos][i] >= 0) {
                        dp[pos][sum] += dp[pos - 1][sum - labels[pos][i]];
                    }
                }
            }
        }
        
        vector <long long> vec(c, c + m);
        if (r / 2 == 2) {
            for (int l1 = 1; l1 <= 50; l1++) {
                add(vec, l1, -1);    

                for (int l2 = 1; l2 <= 50; l2++) {
                    add(vec, l2, -1);

                    vector <long long> q(2);
                    q[0] = l1;
                    q[1] = l2;

                    long long h = hash(vec);
                    if (!Map.count(h) || cmp(q, Map[h])) {
                        Map[h] = q;
                    }

                    add(vec, l2, 1);
                }

                add(vec, l1, 1);
            }
        } else {
            for (int l1 = 1; l1 <= 50; l1++) {
                add(vec, l1, -1);    

                for (int l2 = 1; l2 <= 50; l2++) {
                    add(vec, l2, -1);

                    for (int l3 = 1; l3 <= 50; l3++) {
                        add(vec, l3, -1);

                        vector <long long> q(3);
                        q[0] = l1;
                        q[1] = l2;
                        q[2] = l3;

                        long long h = hash(vec);
                        if (!Map.count(h) || cmp(q, Map[h])) {
                            Map[h] = q;
                        }

                        add(vec, l3, 1);
                    }
                    
                    add(vec, l2, 1);
                }

                add(vec, l1, 1);
            }
        }

        vec.assign(m, 0);
        if (r - r / 2 == 2) {
            for (int l1 = 1; l1 <= 50; l1++) {
                add(vec, l1, 1);    

                for (int l2 = 1; l2 <= 50; l2++) {
                    add(vec, l2, 1);

                    long long h = hash(vec);
                    if (Map.count(h)) {
                        vector <long long> temp = Map[h];
                        temp.push_back(l1);
                        temp.push_back(l2);

                        sort(all(temp));

                        if (cmp(temp, result)) {
                            result = temp;
                            found = true;
                        }
                    }
                    
                    add(vec, l2, -1);
                }

                add(vec, l1, -1);
            }
        } else {
            for (int l1 = 1; l1 <= 50; l1++) {
                add(vec, l1, 1);    
                for (int l2 = 1; l2 <= 50; l2++) {
                    add(vec, l2, 1);

                    for (int l3 = 1; l3 <= 50; l3++) {
                        add(vec, l3, 1);
                        
                        long long h = hash(vec);
                        if (Map.count(h)) {
                            vector <long long> temp = Map[h];
                            temp.push_back(l1);
                            temp.push_back(l2);
                            temp.push_back(l3);

                            sort(all(temp));

                            if (cmp(temp, result)) {
                                result = temp;
                                found = true;
                            }
                        }

                        add(vec, l3, -1);
                    }

                    add(vec, l2, -1);
                }

                add(vec, l1, -1);
            }
        }

        if (!found) {
            printf("Impossible");
        } else {
            printf("Final die face values are ");
            for (int i = 0; i < r; i++) {
                printf("%I64d ", result[i]);
            }
        }

        puts("");
    }
    
    return 0;
}