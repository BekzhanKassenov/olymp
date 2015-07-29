#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int N = 1000100;

struct par {
	int prev, val, l, r, sz;
};
vector<int> pos[N];
vector<par> ans;

par mk(int l, int r, int prev, int val, int sz){
	par tmp = {prev, val, l, r, sz};
	return tmp;
}
int main(){
#ifdef Local
	freopen("in.in", "r", stdin);
#endif
	int n, k;
	cin >> n >> k;
	ans.push_back(mk(-1, -1, -1, -1, -1));
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		ans.push_back(mk(0, 0, 0, -1, -1));
		ans[i] = ans[i-1];
		pos[x].push_back(i);
		if (pos[x].size() >= k){
			int temp = ans[i].sz;
			int left = pos[x][pos[x].size() - k];
			
			if (temp == -1 || temp < ans[left - 1].sz + 1){
				ans[i] = mk(left, i, left - 1, x, ans[left - 1].sz + 1);
			} else if (temp == ans[left - 1].sz + 1 && x < ans[i].val){
				ans[i] = mk(left, i, left - 1, x, ans[left - 1].sz + 1);
			}
		}
	}
	cout << ans[n].sz << endl;
	int tp = n;
	while (tp != 0){
		cout << ans[tp].val << " ";
		tp = ans[tp].prev;
	}
	return 0;
}