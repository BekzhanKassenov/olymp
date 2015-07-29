/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <bitset>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
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
inline T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int t, n, k;

bool prime[100010];

vector <int> primes;
int sz;

void build() {
	memset(prime, true, sizeof prime);

	prime[0] = prime[1] = false;

	for (int i = 2; i < 100010; i++) {
		if (prime[i]) {
			primes.push_back(i);

			if (i * 1ll * i < 100010) {
				for (int j = i * i; j < 100010; j += i)
					prime[j] = false;
			}
		}
	}

	sz = primes.size();
}


int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	scanf("%d", &t);

	build();

	while (t--) {
	 	scanf("%d%d", &n, &k);

	 	vector <pair <int, int> > fact;

		for (int i = 0; i < sz; i++) {
			PII cur;

			cur.F = primes[i];
			while (n % cur.F == 0) {
				cur.S++;
				n /= cur.F;
			}

			if (cur.S)
				fact.push_back(cur);
		}

		if (n > 1) {
			fact.push_back(MP(n, 1));
		}

		vector <bool> sq(k, true);

	    for (int i = 0; i < (int)fact.size(); i++) {
	    	vector <bool> used(k, false);

	    	for (int j = 0; j < k && fact[i].S; j++) {
	    		if (sq[j]) {
	    			fact[i].S--;
	    			sq[j] = false;
	    			used[j] = true;
	    		}
	    	}

	    	bool f = false;

	    	for (int j = 0; j < k && fact[i].S; j++) {
	    		if (!sq[j] && !used[j]) {
	    			f = true;
	    			fact[i].S--;
	    		}
	    	}

	    	while (fact[i].S) {
	    		if (f) {
	    			for (int j = 0; j < k && fact[i].S; j++) {
		    			if (!sq[j] && !used[j]) 
	    					fact[i].S--;
	    		   	}
	    		} else {
	    			for (int j = 0; j < k && fact[i].S; j++) {
	    				if (used[j]) {
	    					fact[i].S--;
	    					sq[j] = sq[j] ^ true;
	    				}
	    			}
	    		}
	    	}

	    	bool can = true;

	    	for (int j = 0; j < k; j++)
	    		if (sq[j])
	    			can = false;

	    	if (can)
	    		break;
	    }

	    bool flag = true;

	    for (int i = 0; i < k; i++)
	    	if (sq[i]) {
	    		flag = false;
	    		break;
	    	}


	    if (flag)
	    	puts("YES");
	    else
	    	puts("NO");	
	}


	return 0;
}
