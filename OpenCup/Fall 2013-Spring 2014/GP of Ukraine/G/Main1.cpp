/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

#define left asdasdas
#define right asdasdasdasd

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int last[3];
int max3(int a, int b, int c){
    int mx = max(a, b);
    return max(mx, c);
}
int lmax3(int i){
    return max3(l[i][0], l[i][1], l[i][2]);
}
int rmax3(int i){
    return max3(r[i][0], r[i][1], r[i][2]);
}
int l[1000001][3], r[1000001][3];
bool comp1(int i, int j){
    if (max3(l[i][0], l[i][1], l[i][2]) > max3(l[j][0], l[j][1], l[j][2]))
        return 1;
    return 0;
}
bool comp2(int i, int j){
    if (max3(r[i][0], r[i][1], r[i][2]) > max3(r[j][0], r[j][1], r[j][2]))
        return 0;
    return 1;
}
int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    string s, t;
    cin >> s >> t;
    int n = s.size();
    s = s + s + s;
    int last[3];
    for (int i = 0; i < n; ++i){
        last[s[i] - 'a'] = i;        
    }
    for (int i = n; i < 2*n; ++i){
        last[s[i] - 'a'] = i;        
        if (t[i - n] == '*'){
            for (int j = 0; j < 3; ++j){
                l[i - n][j] = i - last[j];
            }
        }
    }
    for (int i = 3*n - 1; i >= 2*n; --i){
        last[s[i] - 'a'] = i;        
    }
    for (int i = 2*n - 1; i >= n; --i){
        last[s[i] - 'a'] = i;        
        if (t[i-n] == '*'){
            for (int j = 0; j < 3; ++j)
                r[i - n][j] = last[j] - i;
        }
    }
    vector<int> st;
    vector<int> rt;
    for (int i = 0; i < n; ++i){
        if (t[i] == '*'){
            used[i] = 1;
            st.push_back();
            rt.push_back(i);            
        }
    }
    sort(st.begin(), st.end(), comp1);
    sort(rt.begin(), rt.end(), comp2);
    int ans = 10000000;   
    for (int i = 0; i < n; ++i){
        if (st.size() == 0)
            break;
        while (st.size() && lmax3(st.back()) <= i){
            int rm = st.back();
            st.pop_back();
            int key = rmax3(rm);
            int lp = 0, rp = rt.  
        }
    }
    return 0;
}
