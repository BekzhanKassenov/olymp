#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()

struct BigInt {
 	vector <int> nmb;

 	BigInt() {
 		nmb.push_back(0);
 	}

 	BigInt(const vector <int>& v) {
 		nmb = v;
 	}

 	BigInt(int n) {
 		while (n) {
 			nmb.push_back(n % 10);
 			n /= 10;
 		}
 	}

 	void print() {
 		cut_zeroes();
 		for (int i = nmb.size() - 1; i >= 0; i--)
 			cout << nmb[i];

 		cout << endl;	
 	}

 	void cut_zeroes() {
 		while (!nmb.empty() && nmb.back() == 0)
 			nmb.pop_back();

 		if (nmb.empty())
 			nmb.push_back(0);
 	}

 	BigInt operator + (const BigInt& a) const {
 		int flag = 0;

 		vector <int> ans;

 		int s1 = a.nmb.size(), s = nmb.size();

 		for (int i = 0; i < max(s1, s); i++) {
 			if (i < s1)
 				flag += a.nmb[i];

 			if (i < s)
 				flag += nmb[i];

 			ans.push_back(flag % 10);
 			flag /= 10;	
 		}

 		while (flag) {
 			ans.push_back(flag % 10);
 			flag /= 10;
 		}

 		return BigInt(ans);
 	}

 	BigInt operator * (int k) const {
 		vector <int> ans;

 		long long flag = 0;

 		for (size_t i = 0; i < nmb.size(); i++) {
 			flag += nmb[i] * k;
 			ans.push_back(flag % 10);
 			flag /= 10;
 		}

 		while (flag) {
 			ans.push_back(flag % 10);
 			flag /= 10;
 		}

 		return BigInt(ans);
 	}

 	BigInt operator * (const BigInt& a) const {
 		BigInt ans;

 		for (size_t i = 0; i < a.nmb.size(); i++) {
 			BigInt tmp = (*this) * a.nmb[i];

 			reverse(all(tmp.nmb));

 			for (size_t j = 0; j < i; j++)
 				tmp.nmb.push_back(0);

 			reverse(all(tmp.nmb));

 			ans = ans + tmp;	
 		}

 		return ans;
 	}
};

BigInt dp[55][10 * 55 * 2];
int n, sum;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	cin >> n >> sum;

	if (sum & 1) {
		cout << 0;
		return 0;
	}

	sum /= 2;

	dp[0][0] = BigInt(1);

	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= sum; j++) {
			for (int k = 0; k <= 9 && k <= j; k++) 
				dp[i][j] = dp[i][j] + dp[i - 1][j - k];
		}

	BigInt ans = dp[n][sum] * dp[n][sum];

	ans.print();

	return 0;
}