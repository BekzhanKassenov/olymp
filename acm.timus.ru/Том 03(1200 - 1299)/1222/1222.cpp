#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct BigInt {           
	vector <int> nmb;

	BigInt() {
		nmb.push_back(0);
	}

	BigInt(int n) {
		while (n) {
			nmb.push_back(n % 10);
			n /= 10;
		}
	}

	BigInt(long long n) {
		while (n) {
			nmb.push_back(n % 10);
			n /= 10;
		}
	}

	BigInt(const vector <int>& nmb) : nmb(nmb) {}

	BigInt operator + (const BigInt& a) const {
		vector <int> ans;

		int flag = 0;

		int lena = nmb.size(), len = a.nmb.size();
		
		for (int i = 0; i < max(lena, len); i++) {
		 	if (i < lena)
		 		flag += nmb[i];

		 	if (i < len)
		 		flag += a.nmb[i];

		 	ans.push_back(flag % 10);
		 	flag /= 10;
		}

		while (flag) {
			ans.push_back(flag % 10);
			flag /= 10;
		}

		return BigInt(ans);
	}

	BigInt operator * (int n) const {
		long long flag = 0;

		vector <int> ans;

		for (int i = 0; i < (int)nmb.size(); i++) {
			flag += nmb[i] * n;
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
		BigInt res;

		for (size_t i = 0; i < nmb.size(); i++) {
			BigInt tmp = a * nmb[i];

			if (i > 0) {
				reverse(tmp.nmb.begin(), tmp.nmb.end());

				for (size_t j = 0; j < i; j++)
					tmp.nmb.push_back(0);

				reverse(tmp.nmb.begin(), tmp.nmb.end());	
			}

			res = res + tmp;	
		}

		while (!res.nmb.empty() && res.nmb.back() == 0)
			res.nmb.pop_back();

		if (res.nmb.empty())
			res.nmb.push_back(0);

		return res;	
	}

	BigInt pow(int st) {
		BigInt res(1);

		BigInt a(*this);

		while (st) {
			if (st & 1)
				res = res * a;

			a = a * a;

			st >>= 1;
		}

		return res;
	}

	void print() const {
		for (int i = (int)nmb.size() - 1; i >= 0; i--)
			printf("%d", nmb[i]);

		puts("");
	}
};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	if (n <= 4) {
		cout << n;
		return 0;
	}

	BigInt res(3);

	if (n % 3 == 0) 
		res = res.pow(n / 3);

	if (n % 3 == 1) {
		n -= 4;
		res = res.pow(n / 3);
		res = res * 4;
	}

	if (n % 3 == 2) {
		n -= 2;
		res = res.pow(n /   3);
		res = res * 2;
	}

	res.print();

	return 0;
}
