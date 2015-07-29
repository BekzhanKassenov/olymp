#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[8] = { 2, 2, 1,-1,-2, -2, -1,  1};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;

	getline(cin, s);

	int x = s[0] - 'a' + 1;
	int y = s[1] - '0';

	int x1 = s[4] - 'a' + 1;
	int y1 = s[5] - '0';

	int b[9][9];

	memset(b, 100, sizeof b);

	b[x][y] = 0;

	for (int i = 0; i < 8; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx > 0 && tx < 9)
			if (ty > 0 && ty < 9) {
				if (tx == x1 && ty == y1) {
					cout << 1;
					return 0;
				}
				b[tx][ty] = 1;
			}
	}

	for (int i = 1; i <= 8; i++) 
		for (int j = 1; j <= 8; j++) 
			if (b[i][j] == 1) 
				for (int k = 0; k < 8; k++) {
					int tx = i + dx[k];
					int ty = j + dy[k];

					if (tx > 0 && tx < 9)
						if (ty > 0 && ty < 9) 
							if (tx == x1 && ty == y1) {
								cout << 2;
								return 0;
							}                                                 
				}
		
	cout << "NO";
	return 0;
}