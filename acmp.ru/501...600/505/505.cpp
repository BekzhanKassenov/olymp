#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

map <vector <int>, int> Map;
vector <int> temp;
int l, n, m, x, ok;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d", &l, &m, &n);
    
    temp.resize(l);

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);

        for (int j = 0; j < l; j++)
            scanf("%d", &temp[j]);

        Map[temp] = x;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++)
            scanf("%d", &temp[j]);

        if (!Map.count(temp)) {
            putchar('-');
            putchar('\n');
        } else {
            printf("%d\n", Map[temp]);
            ok++;
        }
    }

    printf("OK=%d BAD=%d\n", ok, n - ok); 

    return 0;
}
