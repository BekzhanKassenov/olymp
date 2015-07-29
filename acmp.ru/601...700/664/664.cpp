#include <cstdio>

using namespace std;

int n, k, m;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &k, &m, &n);

    int ans = 2 * (n / k);

    if (n % k != 0)
        ans++;

    if (n < k || n % k > k / 2)
        ans++;

    ans *= m;
    
    printf("%d\n", ans);
    
    return 0;   
}