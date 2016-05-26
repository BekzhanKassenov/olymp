#include <iostream>
#include <cstdio>
#include <queue>

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

bool ok(int x, int y) {
 	return x >= 0 && x < 4 && y >= 0 && y < 4;
}

void hit(int& mask, int x, int y) {
    int curbit = checkbit(mask, x, y);
    curbit ^= 1;
    setbit(mask, x, y, curbit);

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

bool used[1 << 16];
int dist[1 << 16];

int bfs(int start) {
    queue <int> q;
    q.push(start);
    used[start] = true;
    dist[start] = 0;

    while (!q.empty()) {
        int mask = q.front();
        q.pop();

        if (mask == fullmask || mask == 0) {
            return dist[mask];
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int tmask = mask;
                hit(tmask, i, j);

                if (!used[tmask]) {
                    used[tmask] = true;
                    dist[tmask] = dist[mask] + 1;
                    q.push(tmask);
                }
            }
        }
    }

    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 4; i++) {
    	gets(s[i]);
    }
	
	int mask = 0;
	for (int i = 0; i < 4; i++) {
	 	for (int j = 0; j < 4; j++) {
	 		setbit(mask, i, j, s[i][j] == 'w');
	 	}
	}

    int ans = bfs(mask);
    if (ans != -1) {
        printf("%d\n", ans);
    } else {
        puts("Impossible");
    }
	
	return 0;
}
