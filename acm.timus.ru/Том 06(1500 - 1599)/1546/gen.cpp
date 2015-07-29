#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	freopen("in", "w", stdout);
	srand(time(NULL));

	int n = rand() % 14 + 1;

	while (n--) {
		int len = rand() % 20;

		for (int i = 0; i < len; i++) {
			if (rand() & 1)
				cout << rand() % 10;
			else
				cout << char('a' + rand() % 26);	
		}

		cout << endl;
	}

	return 0;
}
