#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	freopen("sparse.in", "w", stdout);

	srand(time(NULL));

	int n = rand();

	cout << n << ' ' << rand() << ' ' << rand() << ' ' << rand() % n + 1 << ' ' << rand() % n + 1 << endl;

	return 0;
}
