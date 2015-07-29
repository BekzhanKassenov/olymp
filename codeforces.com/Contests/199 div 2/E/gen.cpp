#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen("in", "w", stdout);

	cout << 100000 << ' ' << 100000 << endl;

	for (int i = 0; i < 99999; i++)
		cout << i + 1 << ' ' << i + 2 << endl;

	for (int i = 0; i < 100000; i++)
		cout << 1 << ' ' << i + 1 << endl;

	return 0;	
}
