#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct st {
	pair <int, int> mn, mx; 
	int nmb;

	st() {}

	st(int a, int b, int c, int num) {
		int mi = min(min(a, b), c);
		int ma = max(max(a, b), c);
		mn = make_pair(mi, (a * 1ll + b * 1ll + c * 1ll - mi - ma));
		mx = make_pair((a * 1ll + b * 1ll + c * 1ll - mi - ma), ma);
		nmb = num;
	}

	bool operator < (const st& a) const {
		return (mn.first > a.mn.first);
	}
	bool operator == (const st& a) const {
		return (nmb == a.nmb);
	}
};

st arr[200010], arr1[200010];
priority_queue <st> q;

bool cmp1(const st& a, const st& b) {
	return (a.mn.second > b.mn.second);
}

bool cmp(const pair <int, int>& a, const pair <int, int>& b) {
	return (a.first >= b.first && a.second >= b.second);
}

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 1 << endl << 1;
		return 0;
	}

	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		arr[i] = st(a, b, c, i + 1);
		arr1[i] = arr[i];
	}

	int ans = 0;
	
	sort(arr, arr + n);
	sort(arr1, arr1 + n, cmp1);

	vector <int> res;

	for (int i = 0; i < n; i++) {
		if (cmp(arr[i].mx, arr[0].mn) && cmp(arr[i].mx, arr1[0].mn)) {
			ans++;
			res.push_back(arr[i].nmb);
		}
	}
	sort(res.begin(), res.end());
	cout << ans << endl;
	for (size_t i = 0; i < res.size(); i++)
		cout << res[i] << ' ';
	
	
	return 0;
}