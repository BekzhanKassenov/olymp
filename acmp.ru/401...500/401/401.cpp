#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()

struct big_int {
	vector <int> vec;

	big_int() { }

	big_int(const vector <int>& vec) : vec(vec) { }

	big_int(const big_int& bi) {
		*this = bi;
	}

	big_int(int n) {
		if (n == 0) {
			vec.push_back(0);
		} else {
			while (n) {
				vec.push_back(n % 10);
				n /= 10;
			}
		}
	}

	void operator += (const big_int& temp) {
		int flag = 0;

		size_t lent = temp.vec.size();

		for (size_t i = 0; i < vec.size(); i++) {
			if (i < lent)
				flag += temp.vec[i];

			flag += vec[i];
			vec[i] = flag % 10;
			flag /= 10;	
		}

		for (size_t i = vec.size(); i < lent; i++) {
			flag += temp.vec[i];
			vec.push_back(flag % 10);
			flag /= 10;
		}

		while (flag) {
			vec.push_back(flag % 10);
			flag /= 10;	
		}
	}

	void print() {
		for (int i = vec.size() - 1; i >= 0; i--)
			cout << vec[i];

		cout << endl;	
	}
};

big_int dp[50][50][50];

bool calced[50][50][50];

big_int calc(int n, int a, int b) {
	if (calced[n][a][b]) 
		return dp[n][a][b];

	calced[n][a][b] = true;

	if (n == 0) {
		return (dp[n][a][b] = big_int((a + 1) * (b + 1)));
	}

	big_int res(0);

	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
		  	res += calc(n - 1, a - i, b - j);
		}
	}

	dp[n][a][b] = res;

	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, a, b;

	cin >> n >> a >> b;

	calc(n - 1, a, b).print();

	return 0;
}

