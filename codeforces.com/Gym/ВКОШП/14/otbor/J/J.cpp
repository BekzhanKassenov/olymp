#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <cstring>
#include <fstream>

using namespace std;

const int INF = 2000000000;

template <typename T> 
inline T sqr(T x){
	return (x * x);
}

int tot[1000010];
int c[301][301], n, m;
vector <pair <char, int> > ans;
vector <int> p;
int col[301], row[301], tmp[301][301];
bool uc[301], ur[301];

bool try_(int color){
	ans.clear();
	memset(col, 0, sizeof col);
	memset(row, 0, sizeof row);
	memset(ur, 0, sizeof ur);
	memset(uc, 0, sizeof uc);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = c[i][j];
			if (c[i][j] == color) {
				row[i]++;
				col[j]++;
			}
		}
	}

	int cnt = 0;
	while (true) {
		bool cont = 0;
		
		for (int i = 0; i < n; i++) {
			if (row[i] == m)
				ur[i] = 1;
			
			if (row[i] > m / 2 && !ur[i]) {
				ur[i] = 1;
				ans.push_back(make_pair('R', i + 1));
				cont = 1;
				
				for (int j = 0; j < m; j++) {
					if (tmp[i][j] != color) {
						tmp[i][j] = color;
						col[j]++;
					}
				}
			}
		}

		for (int j = 0; j < m; j++) {
			if (col[j] == n)
				uc[j] = 1;

			if (col[j] > n / 2 && !uc[j]) {
				uc[j] = 1;
				ans.push_back(make_pair('C', j + 1));
				cont = 1;
				
				for (int i = 0; i < n; i++) { 
					if (tmp[i][j] != color) {
						tmp[i][j] = color;
						row[i]++;
					}
				}
			}
		}

		if (!cont)
			break;
	}

	bool cont = 1;
	
	for (int i = 0; i < n; i++)
		cont &= ur[i];
	
	for (int i = 0; i < m; i++)
		cont &= uc[i];

	if (cont) {
		cout << ans.size() << endl;
		
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].first << ' ' << ans[i].second << endl;
		
		return 1;
	}

	return 0;
}

int main() {
	freopen("supreme.in", "r", stdin);
	freopen("supreme.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];	
			tot[c[i][j]]++;
			if (tot[c[i][j]] > (n - 1) * (m - 1) / 4) {
				p.push_back(c[i][j]);
				tot[c[i][j]] = -INF;
			}
		}
	}

	bool was = false;
	
	for (int i = 0; i < p.size(); i++) {
		if (try_(p[i])) {
			was = true;
			break;
		}
	}

	if (!was)
		cout << "Poor Kazimir";
	
	return 0;
}
