/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define MOD (1000 * 1000 * 1000 + 7)

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> 
T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
T sqr(T n) {
	return (n * n);
}

template <typename T>
T max(T a, T b) {
	return (a > b ? a : b);
}

template <typename T>
T min(T a, T b) {
	return (a < b ? a : b);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif


	int n;

	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector <bool> used(n);

	for (int i = 0; i < n; i++)
		if (a[i] < 0) {
			cout << 1 << ' ' << a[i] << endl;
			used[i] = true;
		    break;
		}

	bool flag = false;
			
	for (int i = 0; i < n; i++)
		if (a[i] > 0) {
			flag = true;
			cout << 1 << ' ' << a[i] << endl;
			used[i] = true;
			break;
		}

	if (!flag) {
		cout << 2 << ' ' ;

		int cnt = 2;

		for (int i = 0; i < n && cnt; i++)
			if (a[i] < 0 && !used[i]) {
				cout << a[i] << ' ';
				used[i] = true;
				cnt--;
			}

		cout << endl;	
	}

	if (flag)
		cout << n - 2;
	else
		cout << n - 3;

	cout << ' ';	

	for (int i = 0; i < n; i++)
		if (!used[i])
			cout << a[i] <<  ' ';

   	cout << endl;


	return 0;
}
