/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "stragain"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

ll pow_mod(ll n, int st, ll MOD) {
    ll res = 1;
    
    while (st) {
        if (st & 1) {
            res *= n;
            res %= MOD;
        }
        
        n *= n;
        n %= MOD;
        st >>= 1;
    }
    
    return res;
}

struct Hasher {
    ll base, MOD, *power, *revpower, *hs;
    string s;
    int len;
    
    Hasher() { }
    
    Hasher(ll base, ll MOD, const string& s) : base(base), MOD(MOD), s(s), len(s.size()) { 
        power = new ll[len];
        revpower = new ll[len];
        hs = new ll[len];
        
        power[0] = 1;
        revpower[0] = pow_mod(power[0], MOD - 2, MOD);
        hs[0] = s[0];
        
        for (int i = 1; i < len; i++) {
            power[i] = (power[i - 1] * base) % MOD;
            revpower[i] = pow_mod(power[i], MOD - 2, MOD);
            hs[i] = (power[i] * s[i] + hs[i - 1]) % MOD;
        }
    }
    
    inline ll get_hs(int l, int r) {
        if (l == 0)
            return hs[r];
            
        ll res = (hs[r] - hs[l - 1] + MOD) % MOD;
        
        res = (res * revpower[l]) % MOD;
        
        return res;
    }
};

bool used[3];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    ios_base :: sync_with_stdio(false);
    
    string s, t;
    getline(cin, s);
    getline(cin, t);
    
    int len = s.size();
    
    Hasher hash_s_1(37, MD, s);
    //Hasher hash_s_2(37, MD + 2, s);

    Hasher hash_t_1(37, MD, t);
    //Hasher hash_t_2(37, MD + 2, t); 
    
    pair <ll, pair <int, int> > vec[3];
    
    for (int i = 1; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            vec[0] = MP(hash_t_1.get_hs(0, i - 1), MP(0, i));
            vec[1] = MP(hash_t_1.get_hs(i, j - 1), MP(i, j - i));
            vec[2] = MP(hash_t_1.get_hs(j, len - 1), MP(j, len - j));
            
            used[0] = used[1] = used[2] = false;
            vector <int> ans;
            
            int cur = 0;
            ll hs = 0;
            
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (!used[j]) {
                        if (hs + vec[j].F * hash_s_1.power[cur] == hash_s_1.get_hs(0, cur + vec[j].S.S - 1)) {
                            used[j] = true;
                            hs += vec[j].F * hash_s_1.power[cur];
                            cur += vec[j].S.S;
                            ans.push_back(j);
                        }
                    }
                }
            } 
            
            if (used[0] && used[1] && used[2]) {    
                cout << "YES" << endl;
                            
                for (int i = 0; i < 3; i++)
                    cout << t.substr(vec[ans[i]].S.F, vec[ans[i]].S.S) << endl;
                                
                return 0;
            }
        }
    }
    
    cout << "NO";
    
    return 0;
}
