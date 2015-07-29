#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Meet {
	int _time;
	int x, y;

	void read() {
	 	int hh, mm;
	 	scanf("%d:%d %d %d\n", &hh, &mm, &x, &y);
	 	_time = hh * 60 + mm;
	}

	bool operator < (const Meet& m) const {
	 	return _time < m._time;
	}
};

Meet meet[MAXN];
int n, v, ans;

bool can_be_same(int i, int j) {
	return sqr(meet[i].x - meet[j].x) + sqr(meet[i].y - meet[j].y)
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &v);

    for (int i = 0; i < n; i++) {
     	meet[i].read();
    }

    sort(meet, meet + n);

    for (int i = 0; i < n; i++) {
    	bool found = false;

    	for (int j = 0; j < i && !found; j++) {
    	 	if (can_be_same(i, j) && !used[j]) {
    	 	 	used[j] = true;
    	 	 	found = true;
    	 	}
    	}

    	if (!found)
    		ans++;
    }

    printf("%d\n", ans);

    return 0;
}
