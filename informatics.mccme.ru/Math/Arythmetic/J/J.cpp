#include <cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n = 0;

	char c;

	while ((c = getchar()) && c >= '0' && c <= '9')
		n += c - '0';

	puts((n % 3) ? "NO" : "YES");

	return 0;
}
