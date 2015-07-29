#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

const int lim = (int)1e7;

vector <int> pr, cnt;
bool prime[lim];

void build() {
	memset(prime, 1, sizeof prime);
	prime[0] = prime[1] = 0;

	for (int i = 2; i < (int)1e7; i++) {
		if (prime[i]) {
			pr.push_back(i);

			if (i * 1ll * i < lim) {
			  	for (int j = i * i; j < lim; j += i)
			  		prime[j] = false;
			}
		}
	}

	cnt.resize(pr.size());
}

long long power(long long a, int b) {
  	long long res = 1;

  	for (int i = 0; i < b; i++)
  		res *= a;

  	return res;	
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
   	#endif

   	long long n;

   	cin >> n;

   	build();

   	for (size_t i = 0; i < cnt.size(); i++) {
   		while (n % pr[i] == 0) {
   			n /= pr[i];
   			cnt[i]++;
   		}
   	}

   	long long ans = 1;

   	if (n > 1) {
   		long long tmp = sqrt(n);

   		if (tmp * tmp == n)
   			ans = tmp * tmp;
   	}

   	for (size_t i = 1; i < cnt.size(); i++) {
   		if (cnt[i] & 1)
   			cnt[i]--;

   		ans *= power(pr[i], cnt[i]);
   	}

   	cout << ans;
}
