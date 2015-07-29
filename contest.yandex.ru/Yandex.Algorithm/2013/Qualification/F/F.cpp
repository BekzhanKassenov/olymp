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

bool cmp(const pair <long long, int>& a, const pair <long long, int>& b) {
	return (a.S > b.S);
}

int sum[100010];

vector <pair <int, long long> > b;

bool solve(int n, priority_queue <pair <int, long long> >& q) {
	if (q.size() <= 2)
		return true;

	int t = q.top().F;
	long long tmp = q.top().S;
	q.pop();

	if (t >= n) {
		t -= n;
		if (t != 0)
			q.push(MP(t, tmp));
		return solve(n / 2, q);
	} else
		return false;
}

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	if (n == 1 || n == 2) {
		cout << "YES";
		return 0;
	}

	vector <long long> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(all(a));

	int t = n;

	int cnt = 0;

	while (t > 1) {
		if (t & 1) {
			cout << "NO";
			return 0;
		}
		t >>= 1;
		cnt++;
	}

	b.push_back(MP(1, a[0]));

	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1])
			b.back().F++;
		else
			b.push_back(MP(1, a[i]));
	}


	/*cout << b.size() << endl;

	for (size_t i = 0; i < b.size(); i++)
		cout << b[i].F << ' ' << b[i].S << endl;*/

	priority_queue <pair <int, long long> > s(all(b));

	if (solve(n / 2, s))
		cout << "YES";
	else
		cout << "NO";	

	return 0;
}
