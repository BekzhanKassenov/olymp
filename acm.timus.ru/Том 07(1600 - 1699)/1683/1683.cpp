#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <int> ans;

	int cnt = 0;

	while (n > 1) {
		ans.push_back(n >> 1);
		n -= (n >> 1);
		cnt++;
	}

	cout << cnt << endl;

	for (vector <int> :: iterator it = ans.begin(); it != ans.end(); it++)
		cout << *it << ' ';

}
