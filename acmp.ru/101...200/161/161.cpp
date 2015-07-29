#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 2015;

int phi[MAXN], perm[MAXN], pos[MAXN];
int n;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &phi[i]);
    }

    for (int i = n; i > 0; i--) {
        int cnt = 0;
        
        for (int j = n; j > 0; j--) {
            if (pos[j] == 0) {
                cnt++;
            }

            if (cnt == phi[i] + 1) {
                perm[i] = j;
                pos[j] = i;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", perm[i]);
    }

    puts("");

	return 0;
}
