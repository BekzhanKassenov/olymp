#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int maxn = 1010;
map <string, int> Map, raiting, Num;
int n, len, sw[maxn], m, k, ans[maxn], cur_time;
string s, sng_name[maxn];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s >> len;
		Map[s] = len;
		raiting[s] = 0;
		Num[s] = i;
	}

	cin >> m >> k;

	for (int i = 0; i < m; i++)
		cin >> sng_name[i];

	for (int i = 0; i < k; i++)
		cin >> sw[i];

	int sw_pos = 0;
	
	for (int sng_pos = 0; sng_pos < m; sng_pos++) {
		int new_cur_time = cur_time + Map[sng_name[sng_pos]];

		if (sw_pos < k && new_cur_time > sw[sw_pos]) {
			raiting[sng_name[sng_pos]]--;
			cur_time = sw[sw_pos++];
		} else {
		  	raiting[sng_name[sng_pos]]++;
		  	cur_time = new_cur_time;
		}
	}

	for (map <string, int> :: iterator it = Num.begin(); it != Num.end(); it++) {
	 	ans[it -> second] = raiting[it -> first];
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';

	cout << endl;

	return 0;	
}