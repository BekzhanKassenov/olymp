/****************************************
**        Solution by NU PTZ 2016      **
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

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    int n, a, b;
    vector<pair<int, int> > t[4];
    scanf("%i%i%i", &n, &a, &b);
    for (int i = 0; i < n; i++){
        int type, w;
        scanf("%i%i", &type, &w);
        t[type-1].push_back(make_pair(w, i)); 
    }
    for (int i = 0; i < 3; i++){
        sort(t[i].begin(), t[i].end());
    }
    for (int j = 0; j < 3; j++){
        for (int i = 1; i < (int)t[j].size(); i++){
            t[j][i].first += t[j][i-1].first;
        }        
    }

    int total = min(a, (int)t[0].size()) + min(b, (int)t[1].size());
    int left = max(0, a-(int)t[0].size()) + max(0, b-(int)t[1].size());
    total += min(left, (int)t[2].size());
    int ans = INF;
    int i1 = -1, i2 = -1;
    for (int i = 0; i <= (int)t[2].size(); i++){
        for (int j = 0; j <= (int)t[0].size(); j++){
            int temp = 0;
            if (i > 0) temp += t[2][i-1].first;            
            if (j <= a && total-i-j <= b && total-i-j <= (int)t[1].size()){
                if (j > 0) temp += t[0][j-1].first;
                if (total-i-j > 0) temp += t[1][total-i-j-1].first;
                if (temp < ans){
                    ans = temp;
                    i1 = j;
                    i2 = total-i-j;
                }
            }
        }
    }
    printf("%i %i\n", total, ans);
    for (int i = 0; i < i1; i++){
        printf("%i %i\n", t[0][i].second+1, i+1);
    }
    for (int i = 0; i < i2; i++){
        printf("%i %i\n", t[1][i].second+1, a+i+1);
    }
    int j = 0;
    for (int i = i1; i < a && j < total-i1-i2; i++, j++){
        printf("%i %i\n", t[2][j].second+1, i+1);   
    }
    for (int i = i2; i < b && j < total-i1-i2; i++, j++){
        printf("%i %i\n", t[2][j].second+1, a+i+1);   
    }
    return 0;
}
