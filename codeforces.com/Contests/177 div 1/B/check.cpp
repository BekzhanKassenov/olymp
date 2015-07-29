#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> a;

int n;

int ans = 0;

vector <bool> used;

bool dfs(int v) {
	
	used[v] = true;

	if (a[v] == 0)
		return true;

	if (!used[a[v]])
		return dfs(a[v]);
	else
		return false;
}

bool check()
{
	for (int i = 0; i < n; i++) {
	 	used.assign(n, false);

	 	if (!dfs(i))
	 		return false;
	}

	return true;
}

void calc(int gl) {
	if (gl == n) {
		if (check()) {
			ans ++;

			/*for (int i = 0; i < n; i++)
				cout << a[i] + 1 << ' ';

			cout << endl;*/
		}
	}	
	else {
	 	for (int i = 0; i < n; i++) {
	 	 	a[gl] = i;
	 	 	calc(gl + 1);
	 	}
	}
}

int main() {
	cin >> n;

	a.resize(n);

	calc(0);

	cout << ans;

	return 0;

}