#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

string a[4];

int len;

string s;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

bool ok(int x, int y) {
	return (x >= 0 && x < 4 && y >= 0 && y < 4);
}

bool inst[4][4];

bool dfs(int x, int y, int pos) {
	if (pos == len - 1)
		return true;

	//cout << x << ' ' << y << ' ' << pos << endl;	

	inst[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int t_x = x + dx[i];
		int t_y = y + dy[i];

	   	if (ok(t_x, t_y) && !inst[t_x][t_y] && a[t_x][t_y] == s[pos + 1] && dfs(t_x, t_y, pos + 1)) {
	   		inst[x][y] = false;
	   		return true;
	   	}
	}

	inst[x][y] = false;

	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> a[0] >> a[1] >> a[2] >> a[3];

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;

		len = s.size();

		bool flag = false;

		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				if (a[j][k] == s[0] && dfs(j, k, 0)) {
					flag = true;
					break;
				}

		cout << s << ": ";

		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;	
	}

	return 0;
}