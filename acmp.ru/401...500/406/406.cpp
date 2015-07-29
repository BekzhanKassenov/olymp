#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map <double, int> pos;
double x;
char c, ans[26];
int n, m, cnt[26];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%c %lf\n", &c, &x);
        pos[x] = i;
    }

    for (int i = 0; i < n; i++) {
        c = getchar();

        cnt[c - 'a']++;
    }

    map <double, int> :: iterator it = pos.begin();

    for (int i = 0; i < n; i++) {
        int p = -1;

        for (int j = 0; j < 26; j++) {
            if (cnt[j] != 0 && (p == -1 || cnt[j] < cnt[p]))
                p = j;
        }

        cnt[p] = 0;
        ans[it -> second] = p + 'a';
        it++;
    }

    for (int i = 0; i < n; i++)
        printf("%c\n", ans[i]);

    return 0;
}
