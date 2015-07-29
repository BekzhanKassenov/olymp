#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

bool cmp(const PII& a, const PII& b) {
	if (a.F != b.F)
		return (a.F < b.F);
	
	return (a.S > b.S);
}

int main() {
	freopen("in", "w", stdout);
	srand(time(NULL));
	ios_base :: sync_with_stdio(false);

	int n = rand() % 30 + 1;

	vector <int> a(2 * n);

	for (int i = 0; i <  2 * n; i++) {
		a[i] = rand() % 1000 + 1;
	}

	sort(all(a));

	vector <int> st;
	vector <PII> m;

	for (int i = 0; i < 2 * n; i++) {
		if (st.empty())
			st.push_back(a[i]);
		else {
			if (2 * n - i == st.size()) {
				m.push_back(MP(st.back(), a[i]));
				st.pop_back();
			} else {
				if (rand() & 1)
					st.push_back(a[i]);
				else {
					m.push_back(MP(st.back(), a[i]));
					st.pop_back();
				}	
			}
		}
	}

	sort(all(m));

	cout << n << endl;

	for (int i = 0; i < n; i++)
		cout << m[i].F << ' ' << m[i].S << endl;

   	int x = rand() % 10 + 1;

   	int k = rand() % 1000;

   	cout << x << endl;

   	for (int i = 0; i < x; i++) {
   		cout << k << endl;
   		k += rand() % 100;
   	}

   	return 0;
}