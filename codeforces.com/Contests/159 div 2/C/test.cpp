#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cassert>
#include <ctime>
#include <set>
#include <map>

using namespace std;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif


typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define TASKNAME ""
#define pb push_back
#define mp make_pair
#define EPS (1E-8)
#define INF ((int)1E9)
#define sqr(x) ((x) * (x))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
        
struct pt {
	int x, y;
	
	inline double val() const {
		return atan2(y, x);
	}
	inline bool operator < (const pt &p) const {
		return (fabs(val() - p.val()) < EPS);
	}
};

const int maxn = (int)1e6;
pt ps[maxn];

int main() {     
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;
	while (scanf("%d", &n) >= 1) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &ps[i].x, &ps[i].y);
			if (!ps[i].x && !ps[i].y) {
				while (1) ;
			}
		}
	
		sort(ps, ps + n);
		
		double res = 0;
		for (int i = 0; i < n; i++) {
// 			eprintf("%.18lf\n", ps[i].val());
			double alf = ps[i == n - 1 ? 0 : i + 1].val() - ps[i].val();
			if (alf < -EPS)
				alf += 2 * M_PI;
			res = max(res, alf);
		}
		if (ps[n - 1].val() - ps[0].val() < EPS)
			res = M_PI * 2;
		printf("%.18lf\n", (2 * M_PI - res) / M_PI * 180.0);
		break;
	}	
	return 0;
}