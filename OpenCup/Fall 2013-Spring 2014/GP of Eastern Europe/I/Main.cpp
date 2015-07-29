#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
const int N = 1000100;

struct par{
	int val, l, r, sz;
	par() { }
	par(int val, int l, int r, int sz) : val(val), l(l), r(r), sz(sz) { }
};

vector<int> pos[N];
vector<par> ans;

int main(){
	#ifdef Local	
		freopen("in.in", "r", stdin);
	#endif
	int n, k;
	scanf("%d%d", &n, &k);
	ans.push_back(par(0, 0, 0, 0));
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		ans.push_back(par(0, 0, 0, 0));
		ans[i] = ans[i-1];
		pos[x].push_back(i);
		if ((int)pos[x].size() >= k) {
			int temp = ans[i].sz;
			int left = pos[x][pos[x].size() - k];
//			cout << ans[left - 1].sz + 1 << " " << temp << " " << x <<" " << ans[i].val << " " << ans[left - 1].r << endl;
			if (temp == -1 || (temp < ans[left - 1].sz + 1 && left > ans[left - 1].r)){
				ans[i] = par(x, left, i, ans[left - 1].sz + 1);
			} else if (temp == ans[left - 1].sz + 1 && x < ans[i].val && left > ans[left - 1].r){
				ans[i] = par(x, left, i, ans[left - 1].sz + 1);
			}
		}
				    cout << i << " " << x << " val: " << ans[i].val << " sz: " << ans[i].sz << " l: " << ans[i].l << " r: " << ans[i].r << " " << left << endl;
			
	}
	cout << ans[n].sz*k << endl;
	int tp = n;
	vector<int> vv;
	while (tp > 0) {
		vv.push_back(ans[tp].val);
		tp = ans[tp].l - 1;
	}
	for (int i = vv.size() - 1; i >= 0; i--){
		for (int j = 0; j < k && vv[i] > 0; ++j)
			printf("%d ", vv[i]);
	}
	return 0;
}