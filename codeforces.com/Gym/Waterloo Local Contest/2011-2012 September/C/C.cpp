#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int maxn = 100010;

ll a[maxn];

double lns[maxn];

bool cmp(ll a, ll b) {
	return abs(a) < abs(b);
}

int main() {
 	#ifndef ONLINE_JUDGE
 		freopen("in", "r", stdin);
 	#endif

 	ios_base :: sync_with_stdio(false);

 	int n;

 	cin >> n;

 	for (int i = 0; i < n; i++)
 		cin >> a[i];

 	sort(all(a), cmp);

 	bool flag = true;
 	
 	for (int i = 1; i < n && flag; i++) {
 	 	if (a[i] != a[i - 1])
 	 		flag = false;
 	}

 	if (flag) {
 		cout << 1 << endl;
 		return 0;
 	}

 	flag = true;
 	
 	for (int i = 1; i < n && flag; i++) {
 		if (a[i] != a[i - 1] && a[i] != (-a[i - 1]))
 			flag = false;	
 	}

 	if (flag) {
 		cout << -1;
 		return 0;
 	}

 	lns[0] = log(abs(a[0]));

 	for (int i = 1; i < n; i++)
 		lns[i] = log(abs(a[i])) - lns[0];


}