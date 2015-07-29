#include <iostream>
#include <cstdio>

using namespace std;
                         
void inc_time(int& h, int& m) {
	m++;

	if (m == 60) {
		m = 0;
		h++;
		if (h == 24)
			h = 0;
	}
}

int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);

 	int a, b, c, d;

 	cin >> a >> b >> c >> d;

 	int ans = 0;

 	while (a != c || b != d) {
 		if (b == 30)
 			ans++;

 		if (b == 0) {
 			if (a == 0)
 				ans += 12;

 			if (a > 12)
 				ans += a - 12;

 		   	if (a <= 12)
 		   		ans += a;
 		}

 		inc_time(a, b);
 	}

 	cout << ans;
}
