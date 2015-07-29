#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

const char separator[] = " \n";

int main() {
	srand(time(NULL));
	
	int n = ((rand() << 16) ^ rand()) % 100000 + 1;

	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
	 	printf("%d%c", rand() % 100, separator[i == n - 1]);
	}

	int m = ((rand() << 16) ^ rand()) % 100000 + 1;
	
	printf("%d\n", m);
	for (int i = 0; i < m; i++) {
	 	int type = rand() & 1;

	 	if (type == 0) {
	 	 	int position = ((rand() << 16) ^ rand()) % n;
	 	 	int value = rand() % 100;

	 	   	printf("%d %d %d\n", type, position, value);
	 	} else {
	 	 	int left = rand() % n;
	 	 	int right = left + rand() % (n - left);

	 	 	printf("%d %d %d\n", type, left, right);
	 	}
	}

	return 0;
}
