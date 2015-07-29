#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

const int maxn = 2000000;

int t[maxn];

typedef long long ll;

ll sum(int l) {
	ll res = 0;

	for (int i = l; i >= 0; i = (i & (i + 1)) - 1)
		res += t[i];

	return res;	
}

void upd(int l, int val) {
	for (int i = l; i < maxn; i = (i | (i + 1)))
		t[i] += val;
}

int main() {
 	#ifndef ONLINE_JUDGE
 		freopen("in", "r", stdin);
 		freopen("out", "w", stdout);
 	#endif

 	ios_base :: sync_with_stdio(false);

 	long long res = 0;

 	string s;

 	while ((cin >> s) && (s != "QUIT")) {
 		if (s == "BID" || s == "DEL") {
 		 	double x;

 		 	cin >> x;

 		 	int cnt = (int)(x * 100.0 + 0.01);

 		 	if (s == "BID")
 		 		upd(cnt, 1);
 		 	else
 		 		upd(cnt, -1);
 		} else {
 			int cnt;
 			double x;

 			cin >> x >> cnt;

 			long long ans = sum(maxn) - sum((int)(x * 100.0 - 0.99));

 			res += min(ans, (long long)cnt);

 			//cout << res << endl;

 			//cerr << min(ans, (long long)cnt) << endl;
 		}
 	}

 	cout << res * 0.01;

 	return 0;

}
                          