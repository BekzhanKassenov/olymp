#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, L, a[110];
int left, ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &L, &n);

    for (int i = 0; i < n; i++) {
     	scanf("%d", &a[i]);
    }

    sort(a, a + n);
    n = unique(a, a + n) - a;

   	for (int i = 0; i < n; i++) {
   		if (a[left] + L < a[i] - L) {
   		 	ans++;
   		 	left = i;
   		}
   	}

   	ans++;

   	printf("%d\n", ans);
    return 0;
}
