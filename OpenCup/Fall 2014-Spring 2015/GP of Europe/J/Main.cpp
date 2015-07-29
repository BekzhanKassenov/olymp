/****************************************
**          Solution by NU #2          **
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

enum {
  	W, B
};

int gcd(int a, int b) {
 	while (a && b) {
 	 	a %= b;
 	 	swap(a, b);
 	}

 	return a + b;
}

int T;
vector <pair <int, char> > vec;
int n, k, ans;
char c;
int cnt[2];
int cur[2];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
		scanf("%d\n", &n);
		cnt[W] = cnt[B] = 0;
		cur[W] = cur[B] = 0;
		ans = 0;
		vec.clear();

		for (int i = 0; i < n; i++) {
		 	scanf("%d %c\n", &k, &c);
		 	if (c == 'W')
		 		cnt[W] += k;
		 	else
		 		cnt[B] += k;

			if (vec.empty() || vec.back().second != c) {
				vec.push_back(make_pair(k, c));
			} else {
			 	vec.back().first += k;
			}
		}

		if (cnt[W] == 0 || cnt[B] == 0) {
		 	printf("%d\n", cnt[W] + cnt[B]);
		 	continue;
		}

		int g = gcd(cnt[W], cnt[B]);
		
		cnt[W] /= g;
		cnt[B] /= g;
		
		for (size_t i = 0; i < vec.size(); i++) {
			if (!cur[W] && !cur[B]) {
			 	if (vec[i].second == 'W')
			 		cur[W] += vec[i].first;
			 	else
			 		cur[B] += vec[i].first;

			 	continue;
			}

		 	if (vec[i].second == 'W') {
				long long num = 1ll * cur[B] * cnt[W];
				long long x = num / cnt[B] - cur[W];

				//printf("X : %d\n", x);

				if (num % cnt[B] != 0 || x < 0 || x > vec[i].first) {
					cur[W] += vec[i].first;
				} else {
					cur[W] = vec[i].first - x;
					cur[B] = 0;
					ans++;
				}
		 	} else {
		 	 	long long num = 1ll * cur[W] * cnt[B];
				long long x = num / cnt[W] - cur[B];
				//printf("X : %d\n", x);

				if (num % cnt[W] != 0 || x < 0 || x > vec[i].first) {
					cur[B] += vec[i].first;
				} else {
					cur[B] = vec[i].first - x;
					cur[W] = 0;
					ans++;
				}
		 	}

		 	//printf("W: %d, B: %d\n", cur[W], cur[B]);
		}

		printf("%d\n", ans);
    }
    
    return 0;
}
