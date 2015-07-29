#include <iostream>
#include <cstdio>

using namespace std;

char a[110][110], b[110][110];
char res[2][2];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> m >> n;

	getchar();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = getchar();
		}
		getchar();
	}

	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < m; j++) {
	 		b[i][j] = getchar();
	 	}
	 	getchar();
	}

	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 2; j++) 
			res[i][j] = getchar();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			putchar(res[a[i][j] - '0'][b[i][j] - '0']);
		}
		putchar('\n');
	}

	return 0;
}
