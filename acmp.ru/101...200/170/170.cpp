#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n;
	cin >> n;
	
    int ans = 0;
    for (int cnt = 1; cnt * (cnt - 1) / 2 <= n; cnt++) {
        int sum = cnt * (cnt - 1) / 2;
        if (n - sum > 0 && (n - sum) % cnt == 0) {
            ans = cnt;
        }
    }

    cout << ans << endl;

	return 0;
}
