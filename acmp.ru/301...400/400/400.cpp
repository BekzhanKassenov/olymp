#include <iostream>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

set <int> Set;
map <pair <int, int>, int> Map;
int x, y;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 6; i++) {
        scanf("%d%d", &x, &y);

        if (x > y)
            swap(x, y);

        Map[make_pair(x, y)]++;
        Set.insert(x);
        Set.insert(y);
    }

    if (Set.size() == 1) {
        puts("POSSIBLE");
    } else if (Set.size() == 2) {
        if (Map.size() == 1) {
            puts("IMPOSSIBLE");
        } else {
            map <pair <int, int>, int> :: iterator it = Map.begin(), it1 = ++Map.begin();

            if (it -> second == 4 || it1 -> second == 4)
                puts("POSSIBLE");
            else
                puts("IMPOSSIBLE");
        }
    } else if (Set.size() == 3) {
        if (Map.size() != 3) {
            puts("IMPOSSIBLE");
        } else {
            for (map <pair <int, int>, int> :: iterator it = Map.begin(); it != Map.end(); it++) {
                if (it -> second != 2) {
                    puts("IMPOSSIBLE");
                    return 0;
                }
            }

            puts("POSSIBLE");
        }
    } else {
        puts("IMPOSSIBLE");
    }

    return 0;
}
