#include <set>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
char s[110];
multiset <char> Set;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        gets(s);
        for (int j = 0; s[j]; j++) {
            Set.insert(s[j]);
        }
    }

    for (int i = 0; i < m; i++) {
        gets(s);
        for (int j = 0; s[j]; j++) {
            Set.erase(Set.find(s[j]));
        }
    }

    for (char c: Set) {
        putchar(c);
    }

    puts("");

    return 0;
}
