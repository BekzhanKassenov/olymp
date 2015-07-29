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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

string s, a, b;
int n, na, nb;
int q;
map <string, vector <int> > start;
map <pair <int, int>, int> ans;

bool consists(const string& a, const string& b) {
    int lena = a.size();
    int lenb = b.size();

    if (lena < lenb)
        return false;

    for (int i = 0; i + lenb <= lena; i++) {
        if (a.substr(i, lenb) == b)
            return true;
    }

    return false;
}

int hash_func(const string& str) {
    int res = 0;

    for (size_t i = 0; i < str.size(); i++) {
        res *= 26;
        res += str[i];
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    n = s.size();

    for (int i = 0; i < n; i++) {
        string temp;

        for (int j = 0; j < 4 && i + j < n; j++) {
            temp += s[i + j];
            start[temp].push_back(i);
        }
    }

    cin >> q;
    while (q--) {
        cin >> a >> b;

        na = a.size();
        nb = b.size();

        if (!start.count(a) || !start.count(b)) {
            cout << -1 << endl;
            continue;
        }

        if (consists(a, b)) {
            cout << na << endl;
            continue;
        }

        if (consists(b, a)) {
            cout << nb << endl;
            continue;
        }

        int hasha = hash_func(a);
        int hashb = hash_func(b);
        pair <int, int> hash_pair = MP(min(hasha, hashb), max(hasha, hashb));

        if (ans.count(hash_pair)) {
            cout << ans[hash_pair] << endl;
            continue;
        }
        
        vector <int>& veca = start[a];
        vector <int>& vecb = start[b];

        int lena = veca.size();
        int lenb = vecb.size();
        int asn = n;

        for (size_t i = 0; i < veca.size(); i++) {
            int pos = lower_bound(all(vecb), veca[i]) - vecb.begin();

            if (pos < lenb) {
                asn = min(asn, vecb[pos] + nb - veca[i]);
            }
        }

        for (size_t i = 0; i < vecb.size(); i++) {
            int pos = lower_bound(all(veca), vecb[i]) - veca.begin();

            if (pos < lena) {
                asn = min(asn, veca[pos] + na - vecb[i]);
            }
        }

        ans[hash_pair] = asn;

        cout << asn << endl;
    }

    return 0;
}
