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
int dp[22][1010];
int faces[22];
vector <int> labels[22];
vector <int> result;
map <long long, vector <long long> > Map;
bool found = false;

ostream& operator << (ostream& out, const vector <int>& vec) {
    out << '{';
    for (size_t i = 0; i + 1 < vec.size(); i++) {
        out << vec[i] << ", ";
    }

    out << vec.back() << '}';
    return out;
}

bool cmp(const vector <int>& a, const vector <int>& b) {
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }

    return false;
}

long long hash(const vector <int>& vec) {
    long long result = 0;

    for (size_t i = 0; i < vec.size(); i++) {
        result *= 51;
        result += vec[i];
    }

    return result;
}

void unhash(long long h, vector <int>& vec) {
    int pos = 0;
    while (h > 0) {
        vec[pos++] = h % 51;
        h /= 51;
    }
}

void add(vector <int>& vec, int label, int mul) {
    for (int j = 0; j < m; j++) {
        if (0 <= v[j] - label && v[j] - label < MAXDP) {
            vec[j] += mul * dp[n - 1][v[j] - label];
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    for (scanf("%d", &n); n != 0; scanf("%d", &n)) {
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
        
        result.assign(r, 50);
        Map.clear();
        found = false;

        for (int i = 0; i < faces[0]; i++) {
            dp[0][labels[0][i]] = 1;
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
        
        vector <int> vec(c, c + m);
        if (r / 2 == 2) {
            for (int l1 = 1; l1 <= 50; l1++) {
                add(vec, l1, -1);    

                for (int l2 = 1; l2 <= 50; l2++) {
                    add(vec, l2, -1);

                    vector <int> q(2);
                    q[0] = l1;
                    q[1] = l2;

                    sort(all(q));
                    long long h = hash(vec);
                    Map[h].push_back(hash(q));

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

                        vector <int> q(3);
                        q[0] = l1;
                        q[1] = l2;
                        q[2] = l3;

                        sort(all(q));
                        long long h = hash(vec);
                        Map[h].push_back(hash(q));

                        add(vec, l3, 1);
                    }
                    
                    add(vec, l2, 1);
                }

                add(vec, l1, 1);
            }
        }

        for (map <long long, vector <long long> > :: iterator it = Map.begin(); it != Map.end(); it++) {
            sort(all(it->second));
            (it->second).resize(unique(all(it->second)) - (it->second).begin());
        }

        vec.assign(m, 0);
        if (r - r / 2 == 2) {
            for (int l1 = 1; l1 <= 50; l1++) {
                add(vec, l1, 1);    

                for (int l2 = 1; l2 <= 50; l2++) {
                    add(vec, l2, 1);

                    long long h = hash(vec);
                    if (Map.count(h)) {
                        for (vector <long long> :: iterator it = Map[h].begin(); it != Map[h].end(); it++) {
                            vector <int> temp(r / 2);
                            
                            unhash(*it, temp);
                            temp.push_back(l1);
                            temp.push_back(l2);

                            sort(all(temp));
                            found = true;

                            if (cmp(temp, result)) {
                                result = temp;
                            }
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
                            for (vector <long long> :: iterator it = Map[h].begin(); it != Map[h].end(); it++) {
                                vector <int> temp(r / 2);
                                
                                unhash(*it, temp);
                                temp.push_back(l1);
                                temp.push_back(l2);
                                temp.push_back(l3);

                                sort(all(temp));
                                found = true;

                                if (cmp(temp, result)) {
                                    result = temp;
                                }
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
                printf("%d ", result[i]);
            }
        }

        puts("");
    }
    
    return 0;
}
