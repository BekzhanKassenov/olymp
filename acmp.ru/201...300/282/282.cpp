#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int w, h;

	cin >> w >> h;

	long long ans = 0;

	for (int i = 0; i <= w; i++) {
		for (int j = 0; j <= h; j++) { 
			ans += (w - i) * (h - j);	
		}
	}

	cout << ans;

	return 0;
}