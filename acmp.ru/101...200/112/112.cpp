#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int merge_count(vector <int> :: iterator l1, vector <int> :: iterator r1,
				vector <int> :: iterator l2, vector <int> :: iterator r2,
				vector <int>& res) {
	int result = 0;
	res.clear();

	while (true) {
		if (l1 == r1) {
			while (l2 != r2) {
				res.push_back(*l2);
				l2++;
			}
			break;
		}

		if (l2 == r2) { 
			while (l1 != r1) {
				res.push_back(*l1);
				l1++;
			}
			break;
		}

		if (*l1 < *l2) 
			res.push_back(*l1++);
		else {
			res.push_back(*l2++);
			result += (r1 - l1);
		}
	}

	return result;
}

int count_inversions(vector <int>& vec) {
	if (vec.empty() || vec.size() == 1)
		return 0;

	int mid = vec.size() >> 1;
	vector <int> l_vec, r_vec;
	l_vec.resize(mid);
	r_vec.resize(vec.size() - mid);

	copy(vec.begin(), vec.begin() + mid, l_vec.begin());
	copy(vec.begin() + mid, vec.end(), r_vec.begin());


	int result = count_inversions(l_vec) + count_inversions(r_vec);

	vector <int> temp;
	result += merge_count(l_vec.begin(), l_vec.end(), r_vec.begin(), r_vec.end(), temp);
	vec = temp;

	return result;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;

	cin >> n >> k;

	vector <int> a(n);

	int ans = 0;

	while (k--) {
		for (int i = 0; i < n; i++)
			cin >> a[i];

		ans += count_inversions(a);
	}

	cout << ans;

	return 0;	
}
