#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	freopen("in", "r", stdin);

	int a, b;

	cin >> a >> b;

	for (int i = 2; i <= (max(a, b)); i++)
		if (a % i == b % i)
			cout << i << endl;

	return 0;
}
