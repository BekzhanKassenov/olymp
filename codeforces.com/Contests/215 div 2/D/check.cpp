#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int k = 0;

	for (int n = 2; n <= 64; n++) {
		bool flag = true;
		for (int i = 2; i * i <= n && flag; i++)
			if (n % i == 0) {
				flag = false;
			}

		k += flag;
		if (flag)
			cout << "YES " << n << endl;
	}

	cout << k << endl;

	return 0;
}