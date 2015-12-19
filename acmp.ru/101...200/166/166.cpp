#include <cstdio>

using namespace std;

int mem[200];
int *delta = mem + 2;
int n, k;

int max(int a, int b) {
	if (a > b)
		return a;

	return b;
}

int robots(int year) {
 	return delta[year] + delta[year - 1] + delta[year - 2];
}

int new_generation(int current) {
	int result = 0;
    int iter = 0;

	for (int multiple5 = current / 5; multiple5 >= 0; multiple5--) {
	 	int multiple3 = (current - multiple5 * 5) / 3;

		result = max(result, multiple3 * 5 + multiple5 * 9);

        iter++;
        if (iter > 50) {
            break;
        }
	}

	return result;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &k, &n);

	delta[1] = k;

	for (int i = 1; i < n; i++) {
	 	int current = robots(i);
	 	delta[i + 1] = new_generation(current);
	}

	printf("%d\n", robots(n));

	return 0;
}
