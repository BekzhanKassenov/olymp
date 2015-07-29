#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll base = 39;
const ll MOD = 1000000 + 7;

ll hash(const string& s) {
	ll res = 0;

	for (int i = 0; i < (int)s.size(); i++) 
		res = (res * base + s[i]) % MOD;

	return res;	
}

int cnt[MOD];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
   	#endif

   	int n;

   	cin >> n;

   	vector <vector <ll> > a(n, vector <ll> (3));

   	for (int i = 0; i < n; i++) {
   		string s;

   		for (int j = 0; j < 3; j++) {
   			cin >> s;
   			a[i][j] = hash(s);
   		}
   	}

   	int ans = 0;
   	                        
   	for (int mask = 1; mask < (1 << n); mask++) {
   		vector <ll> tmp;

   		int cur = 0;

   		bool flag = true;

   		for (int i = 0; i < n; i++) {
   			if (mask & (1 << i)) {
   				for (int j = 0; j < 3; j++) {
   					cnt[a[i][j]]++;
   					
   					if (cnt[a[i][j]] > 1)
   						flag = false;
   				}

   				cur++;
   			}
   		}

   		for (int i = 0; i < n; i++) 
   			if (mask & (1 << i)) 
   				for (int j = 0; j < 3; j++) 
   					cnt[a[i][j]]--;

   	  	if (flag)
   	  		ans = max(ans, cur);
   	}

   	cout << ans;
}
