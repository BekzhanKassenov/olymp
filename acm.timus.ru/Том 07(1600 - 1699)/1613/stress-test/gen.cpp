#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int get_rand(int m = -1) {
	if (m == -1)
		return ((rand() << 16) + rand());

	return ((rand() << 16) + rand()) % m;
}

int main() {
	freopen("in", "w", stdout);
	
	ios_base :: sync_with_stdio(false);
	
	srand(time(NULL));

	int n = get_rand(70000) + 1;

	int m = get_rand(100000) + 1;

	cout << n << endl;

	vector <int> a(n);

	for (int i = 0; i < n; i++) {
		a[i] = get_rand();
		cout << a[i] << " \n"[i == n - 1];
	}

	cout << m << endl;

	for (int i = 0; i < m; i++) {
		int l = get_rand(n);

		int r = l + get_rand(n - l);

		cout << l + 1 << ' ' << r + 1 << ' ';

		if (rand() & 1) 
			cout << a[l + get_rand(r - l + 1)];
		else
			cout << get_rand();

		cout << endl;	
	}

	return 0;
}
