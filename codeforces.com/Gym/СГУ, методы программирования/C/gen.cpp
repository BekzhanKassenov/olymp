#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen("in", "w", stdout);
	cout << 50000 << ' ' << 50000 << endl;

	int n = 50000;

	for (int i = 0; i < n; i++) {
		cout << (i + 1) * 2 << ' ';
	}

	cout << endl;

	for (int i = 0; i < n; i++)
		cout << 1 << ' ' << n << endl;

	return 0;	
}
