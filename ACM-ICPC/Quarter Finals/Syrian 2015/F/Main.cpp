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
const string abcde = "ABCDE";

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
char s[8];

char merge(char a, char b) {
    int levela = a - 'A' + 1;
    int levelb = b - 'A' + 1;

    return levela + levelb + 'A' - 1;
}

bool check(const string& s) {
    for (char c: abcde) {
        if (s.find(c) == string::npos) {
            return false;
        }
    }

    return true;
}

bool solve(char s[]) {
    for (int i = 0; i < 7; i++) {
       for (int j = i + 1; j < 7; j++) {
           string temp;
           for (int q = 0; q < 7; q++) {
               if (q != i && q != j) {
                   temp.push_back(s[q]);
               }
           }

           temp.push_back(merge(s[i], s[j]));
           if (check(temp)) {
               return true;
           }
       }
   }

    for (int i = 0; i < 7; i++) {
       for (int j = i + 1; j < 7; j++) {
           for (int k = 0; k < 7; k++) {
               for (int l = k + 1; l < 7; l++) {
                   if (k != i && k != j && l != i && l != j) {
                       string temp;
                       for (int q = 0; q < 7; q++) {
                           if (q != i && q != j && q != k && q != l) {
                               temp.push_back(s[q]);
                           }
                       }

                       temp.push_back(merge(s[i], s[j]));
                       temp.push_back(merge(s[k], s[l]));

                       if (check(temp)) {
                            return true;
                       }
                   }
               }
           }
       }
   }

   return false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &T);

    while (T--) {
        gets(s);

        if (solve(s)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    
    return 0;
}
