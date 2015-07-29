#include <iostream>
#include <cstdio>

using namespace std;

const int fullmask = (1 << 16) - 1;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};

void setbit(int& mask, int i, int j, int val) {
	int offset = (i << 2) | j;
	mask ^= mask & (1 << offset);
	mask |= val << offset;
}

int checkbit(int mask, int i, int j) {
 	return (mask >> ((i << 2) | j)) & 1;
}

char s[5][5];
int dp[1 << 16];
bool calced[1 << 16];

bool ok(int x, int y) {
 	return x >= 0 && x < 4 && y >= 0 && y < 4;
}

void hit(int& mask, int x, int y) {
 	for (int i = 0; i < 4; i++) {
 	 	int tx = x + dx[i];
 	 	int ty = y + dy[i];

 	 	if (ok(tx, ty)) {
			int curbit = checkbit(mask, tx, ty);
			curbit ^= 1;
			setbit(mask, tx, ty, curbit);
 	 	}
 	}
}

int can(int mask) {
 	if (mask == 0 || mask == fullmask) {
 	 	return dp[mask] = 0;
 	}

 	if (calced[mask])
 		return dp[mask];

 	calced[mask] = true;

 	for (int i = 0; i < 4; i++) {
 	 	for (int j = 0; j < 4; j++) {
 	 	 	hit(mask, i, j);
 	 	 	int result = can(mask);
 	 	 	hit(mask, i, j);

 	 	 	if (result != -1 && (dp[mask] == -1 || dp[mask] > result + 1))
 	 	 		dp[mask] = result + 1;
 	 	}
 	}

 	return dp[mask];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

    memset(dp, 255, sizeof dp);
    for (int i = 0; i < 4; i++)
    	gets(s[i]);
	
	int mask = 0;
	for (int i = 0; i < 4; i++) {
	 	for (int j = 0; j < 4; j++) {
	 		setbit(mask, i, j, s[i][j] == 'w');
	 	}
	}

	int result = can(mask);
	if (result != -1) {
	 	printf("%d\n", result);
	} else {
	 	puts("Impossible");
	}
	
	return 0;
}
