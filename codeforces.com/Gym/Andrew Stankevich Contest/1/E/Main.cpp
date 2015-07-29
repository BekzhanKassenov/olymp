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
#define File "nice"

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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

long long m, p;
string str;
bool check(int i, int j){
    for (int k = 1; k < m; ++k){
        if ((i&(1<<k)) == (j&(1<<k)) && (i&(1<<(k-1))) == (j&(1<<(k-1))) && ((i&(1<<k))>>1) == (j&(1<<(k-1))))
            return 0;
    }   
    return 1;
}
struct BigInt {
    vector <int> nmb;

    BigInt() {
        nmb.push_back(0);
    }      

    BigInt(const string& s) {
        nmb.reserve(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            nmb.push_back(s[i] - '0');
        }
    }

    BigInt(const BigInt& p) {
        nmb = p.nmb;
    }

    int mod2() {
        return (nmb[0] % 2);
    }

    void div2() {
        vector <int> temp;

        int cur = 0;

        for (int i = nmb.size() - 1; i >= 0; i--) {
            cur *= 10;
            cur += nmb[i];
            temp.push_back(cur / 2);
            cur %= 2;
        }

        while (cur > 1) {
            temp.push_back(cur / 2);
            cur %= 2;
        }

        reverse(all(temp));

        while (!temp.empty() && temp.back() == 0)
            temp.pop_back();

        if (temp.empty())
            temp.push_back(0);

        nmb = temp;
    }

    vector <char> bin_pres() {
        BigInt tmp;
        tmp.nmb = nmb;

        vector <char> res;

        while (tmp.nmb.back() != 0) {
            res.push_back(tmp.mod2());
            tmp.div2();
        }

        return res;
    }

    void operator -= (int k) {
        nmb[0] -= k;

        for (size_t i = 0; i < nmb.size(); i++) {
            if (nmb[i] < 0) {
                nmb[i] += 10;
                nmb[i + 1]--;
            }
        }

            
        while (!nmb.empty() && nmb.back() == 0)
            nmb.pop_back();

        if (nmb.empty())
            nmb.push_back(0);   
    }


    void print() {
        for (int i = nmb.size() - 1; i >= 0; i--)
            cout << nmb[i];
        cout << endl;   
    }
};

long long d[500][33][34];
long long ans[33][33];
long long tem[33][33];
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    cin >> str >> m >> p;
    
    BigInt nn(str);
    nn -= 1;
    vector<char> bb = nn.bin_pres();

    int sz = (1<<m);
    for (int i = 0; i < sz; ++i){
        for (int j = 0; j < sz; ++j){
        if (i == j)
            ans[i][j] = 1;
            if (check(i, j))
                 d[1][i][j] = 1;
        }
    }   
    for (int i = 2; i < 470; ++i){
        for (int j = 0; j < sz; ++j){
            for (int k = 0; k < sz; ++k){
                long long tp = 0;
                    for (int l = 0; l < sz; ++l){
                        tp += (d[i-1][j][l]*d[i-1][l][k])%p;
                        tp %= p;
                    }
                    d[i][j][k] = tp%p;
            }
        }
    }                   
//  reverse(all(bb));
    for (int i = 0; i < (int)bb.size(); ++i){
        //cout << (int)bb[i];
        if (bb[i]){
            for (int j = 0; j < sz; ++j){
                for (int k = 0; k < sz; ++k){
                    long long tp = 0;
                        for (int l = 0; l < sz; ++l){
                            tp += (d[i+1][j][l]*ans[l][k])%p;
                            tp %= p;
                            }
                        tem[j][k] = tp%p;
                }
            }       
        
        for (int k = 0; k < sz; ++k){
            for (int j = 0; j < sz; ++j){
                ans[k][j] = tem[k][j];
            }
        }
        }       
    }
    long long res = 0;
    for (int i = 0; i < sz; ++i){
        for (int j = 0; j < sz; ++j){
            res += ans[i][j];
            //cout << ans[i][j] << " ";
            res %= p;
        }
    //  cout << endl;
    }                  
/*  for (int i = 0; i < sz; ++i){
        for (int j = 0; j < sz; ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }         */         
    cout << res;
    return 0;
}

