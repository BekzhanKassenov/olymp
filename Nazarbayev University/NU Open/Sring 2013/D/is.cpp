#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	freopen("out", "w", stdout);

	int n;
	
	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		a[i] = i;


	do {
		vector <int> tmp;

		int mn = 10000;

		for (int i = 0; i < n; i++)
			if (mn > a[i]) {
				tmp.push_back(a[i]);
				mn = a[i];
			}

		for (int i = 0; i < n; i++)
			cout << a[i] + 1 << ' ';

		cout << " ----> ";

		for (size_t i = 0; i < tmp.size(); i++)
			cout << tmp[i] + 1 << ' ';

		cout << endl;	

	} while (next_permutation(a.begin(), a.end()));

	return 0;
}
