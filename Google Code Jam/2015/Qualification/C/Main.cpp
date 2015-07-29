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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Quaternion {
    char c;
    bool sign;

    Quaternion() { }

    Quaternion(char c, bool sign) : c(c), sign(sign) { }

    Quaternion operator * (const Quaternion& other) const {
        static map <Quaternion, map <Quaternion, Quaternion> > table;
        static bool init = false;

        if (!init) {
            init = true;
            table[Quaternion('1', false)][Quaternion('1', false)] = Quaternion('1', false);
            table[Quaternion('1', false)][Quaternion('i', false)] = Quaternion('i', false);
            table[Quaternion('1', false)][Quaternion('j', false)] = Quaternion('j', false);
            table[Quaternion('1', false)][Quaternion('k', false)] = Quaternion('k', false);
            table[Quaternion('i', false)][Quaternion('1', false)] = Quaternion('i', false);
            table[Quaternion('i', false)][Quaternion('i', false)] = Quaternion('1', true);
            table[Quaternion('i', false)][Quaternion('j', false)] = Quaternion('k', false);
            table[Quaternion('i', false)][Quaternion('k', false)] = Quaternion('j', true);
            table[Quaternion('j', false)][Quaternion('1', false)] = Quaternion('j', false);
            table[Quaternion('j', false)][Quaternion('i', false)] = Quaternion('k', true);
            table[Quaternion('j', false)][Quaternion('j', false)] = Quaternion('1', true);
            table[Quaternion('j', false)][Quaternion('k', false)] = Quaternion('i', false);
            table[Quaternion('k', false)][Quaternion('1', false)] = Quaternion('k', false);
            table[Quaternion('k', false)][Quaternion('i', false)] = Quaternion('j', false);
            table[Quaternion('k', false)][Quaternion('j', false)] = Quaternion('i', true);
            table[Quaternion('k', false)][Quaternion('k', false)] = Quaternion('1', true);
        }

        Quaternion result(table[Quaternion(this->c, false)][Quaternion(other.c, false)]);
        result.sign ^= this->sign;
        result.sign ^= other.sign;

        return result;
    }

    bool operator < (const Quaternion& other) const {
        if (c != other.c) {
            return c < other.c;
        }

        return sign < other.sign;
    }

    bool operator == (const Quaternion& other) const {
        return c == other.c && sign == other.sign;
    }

    friend ostream& operator << (ostream& out, const Quaternion& q);
};

ostream& operator << (ostream& out, const Quaternion& q) {
    if (q.sign) {
        out << '-';
    }

    out << q.c;
    return out;
}

Quaternion suff[MAXN];
int T;
int x, l, n;
int casenum;
char buf[MAXN], s[MAXN];
bool result;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &T);
    
    while (T--) {
        casenum++;
        scanf("%d %d\n", &l, &x);
        gets(buf);
        result = false;

        n = l * x;
        for (int i = 0; i < x; i++) {
            strcpy(s + l * i, buf);
        }
        
        suff[n - 1] = Quaternion(s[n - 1], false);
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = Quaternion(s[i], false) * suff[i + 1];
        }

        Quaternion curi('1', false);
        for (int i = 0; i + 1 < n && !result; i++) {
            curi = curi * Quaternion(s[i], false);
            
            if (curi == Quaternion('i', false)) {
                Quaternion curj('1', false);
                for (int j = i + 1; j + 1 < n && !result; j++) {
                    curj = curj * Quaternion(s[j], false);

                    if (curj == Quaternion('j', false) && suff[j + 1] == Quaternion('k', false)) {
                        result = true;
                    }
                }
            }
        }

        if (result) {
            printf("Case #%d: YES\n", casenum);
        } else {
            printf("Case #%d: NO\n", casenum);
        }
    }
    
    return 0;
}
