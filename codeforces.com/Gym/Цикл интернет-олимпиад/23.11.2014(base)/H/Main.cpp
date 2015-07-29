/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "strings"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;
const int BASE = 29;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXN];
int n;
vector <char> mx;
int cnt[26];
int mxx = 0;
vector <int> pos[26];
bool used[26];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    gets(s);
    n = strlen(s);

    for (int i = 0; i < n; i++) {
	    cnt[s[i] - 'a']++;
	    pos[s[i] - 'a'].push_back(i);
	    mxx = max(mxx, cnt[s[i] - 'a']);
    }

    for (int i = 0; i < 26; i++) {
     	if (cnt[i] == mxx) {
     	 	mx.push_back(i + 'a');
     	}
    }

    int ans = 1;
    for (size_t i = 0; i < mx.size(); i++) {
     	char c = mx[i];
     	memset(used, 0, sizeof used);
     	used[c - 'a'] = true;

     	for (int j = 1; j < 26; j++) {
     		if (pos[c - 'a'][0] + j >= n)
     			break;

     		char cc = s[pos[c - 'a'][0] + j];

     		if (used[cc - 'a'])
     			break;

     		used[cc - 'a'] = true;
     		bool ok = true;
     		for (size_t k = 1; k < pos[c - 'a'].size() && ok; k++) {
				if (pos[c - 'a'][k] + j < n && s[pos[c - 'a'][k] + j] != cc)
					ok = false;
     		}

     		if (ok)
     			ans = max(ans, j + 1);
     	}	         	
    }

    printf("%d\n", ans);

    return 0;
}
