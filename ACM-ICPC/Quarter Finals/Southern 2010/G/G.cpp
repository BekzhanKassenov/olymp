/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

const int maxn = 200010;

PII a[maxn];
int mx[maxn];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    scanf("%d", &n);
    n--;

    char c;
    int x;

    for (int i = 0; i < n; i++) {
    	cin >> c >> x;

     	if (c == 'd')
     		a[i].F = 1;
     	else
     		a[i].F = 2;

     	a[i].S = x;
    }

    if (a[0].F == 1)
    	mx[0] = 1;
    else
    	mx[0] = 0;

  	for (int i = 1; i < n; i++) {
  		if (a[i].F == 2)
  			mx[i] = min(mx[i - 1], a[i].S);
  		else
  			mx[i] = mx[i - 1] + 1;
	}	

	set <PII> s;

	for (int i = 0; i < n - 1; i++) {
		if (a[i].F == 1) {
			s.insert(MP(a[i].S, i));
		} else {
			int sz = s.size();

			while (sz >= a[i].S) {
				s.erase(s.begin());
				sz--;
			}
		}
	}

	int ans = 0;

	for (set <PII> :: iterator it = s.begin(); it != s.end(); it++)
		ans += it -> F;

	if ((int)s.size() < a[n - 1].S) {
		puts("-1");
		return 0;
	}   

	cout << ans << endl << s.size() << endl;

	vector <int> res;

	for (set <PII> :: iterator it = s.begin(); it != s.end(); it++)
		res.push_back(it -> S + 2);

	sort(all(res));

	for (int i = 0; i < (int)res.size(); i++)
		cout << res[i] << ' ';
	return 0;
}
