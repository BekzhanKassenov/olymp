#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cstring>
#include <cassert>
#include <cmath>
#include <bitset>

const int MAXN = 1111;

using namespace std;
int n, num[MAXN];

char stake[MAXN][MAXN];
int black[MAXN];
int sz[MAXN];
string s;
int b, c;

int ans = 0;
int black_cnt = 0, c_cnt = 0;
int iter = 0;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 0  ; i < n ; i ++) {
		scanf("%d ", &num[i]);
		getline(cin, s);
		for (int j = 0; j < (int) s.length(); j++) {
			if (s[j] != 'b' && s[j] != 'c')
				continue;
			if (s[j] == 'b') {
				if (sz[i] == 0 || stake[i][sz[i] - 1] == 'c') {
					sz[i]++;
					stake[i][sz[i] - 1] = 'b';
					black_cnt++;
					black[i]++;
				}
			}
			else {
				if (sz[i] == 0 || stake[i][sz[i] - 1] == 'b') {
					sz[i]++;
					stake[i][sz[i] - 1] = 'c';
					c_cnt++;
				}
			}
		}
	}
	for (int i = 0 ; i < n ; i ++) reverse(stake[i], stake[i] + sz[i]);

	if (n == 1) {
		if (stake[0][sz[0] - 1] == 'b') {
			ans++;
			sz[0]--;
			black_cnt--;
		}

		if (black_cnt > 1) {
			puts("-1");
			return 0;
		}

		if (sz[0] == 3) 
			ans += 2;
		else if ((int) sz[0] > 0)
			ans += 1;

		printf("%d\n", ans);

		return 0;
	}

	for (int i = 0; i < n; i++)
		if (stake[i][sz[i] - 1] == 'b') { 
			ans++;
			sz[i]--;
			black_cnt--;
			black[i]--;
		}

	int super = -1;
	for (int i = 0; i < n; i++)
		if (stake[i][sz[i] - 1] == 'c') 
			super = i;

	if (super == -1) {
		printf("%d\n", ans);
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (super == i)
			continue;
		while (sz[i] > 0) {
			if (stake[i][sz[i] - 1] == 'b') {
				ans++;
				sz[i]--;
				black_cnt--;
				black[i]--;
			}
			else {
				if (sz[i] == 1) {
					ans++; sz[i]--;
				}
				else if (black[i] == 0) {
					ans++; sz[i] = 0;
				}
				else if (sz[i] == 3 && black_cnt == 1) {
					ans += 2; sz[i] = 0; 
					black_cnt--;
				}
				else if (sz[i] == 2 && black_cnt == 1) {
					ans += 1; sz[i] = 0;
					black_cnt--;
				}
				else {
					ans++; sz[i]--;
				}
			}
		}
	}
	bool c_near = false;
	while (sz[super] > 0) {
		if (stake[super][sz[super] - 1] == 'b') {
			ans++;
			sz[super]--;
			black_cnt--;
			black[super]--;
		}
		else {
			
			if (sz[super] == 1) {
				ans++; sz[super]--;
			}
			else if (black[super] == 0) {
				ans++; sz[super] = 0;
			}
			else if (sz[super] == 3 && black_cnt == 1) {
				ans += 2; sz[super] = 0; 
				black_cnt--;
			}
			else if (sz[super] == 2 && black_cnt == 1) {
				ans += 1; sz[super] = 0;
				black_cnt--;
			}
			else {
				ans ++; sz[super]--; c_near = true;
			}
		}
		
	}
	ans += c_near;
	printf("%d\n", ans);
	return 0;
}
