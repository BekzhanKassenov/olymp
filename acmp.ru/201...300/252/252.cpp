#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define F first
#define S second
#define MP make_pair

typedef double ll;

ll to_grams(const pair <ll, string>& p1) {
	ll cnt = p1.F;

	char type = p1.S[0];

	if (p1.S.size() == 2) {
		type = p1.S[1];

		if (p1.S[0] == 'm')
			cnt /= 1000.0;
		else if (p1.S[0] == 'k')
			cnt *= 1000.0;
		else if (p1.S[0] == 'M')
			cnt *= 1000000.0;
		else if (p1.S[0] == 'G')
			cnt *= 1000000000.0;
	}
	if (type == 'p')
		cnt *= 16380.0;
	else if (type == 't')
		cnt *= 1000000.0;

	return cnt;	
}

bool cmp(const pair <ll, string>& p1, const pair <ll, string>& p2) {
	return (to_grams(p1) < to_grams(p2));
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	vector <pair <ll, string> > a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S;

	stable_sort(a.begin(), a.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << a[i].F << ' ' << a[i].S << endl;	

	return 0;
}
