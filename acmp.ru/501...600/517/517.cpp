#include <iostream>
#include <cstdio>

using namespace std;

int n, a[50];
int pos, result;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
	 	scanf("%d", &a[i]);
	}

	for (int i = 0; i < 10; i++) {
		result += a[pos];

		if (a[pos] == 10) {
		 	result += a[pos + 1] + a[pos + 2];
		 	pos++;
		} else {
			result += a[pos + 1];
			
			if (a[pos] + a[pos + 1] == 10) {
			 	result += a[pos + 2];
			}
			
			pos += 2;
		}
	}

	printf("%d\n", result);

	return 0;
}
