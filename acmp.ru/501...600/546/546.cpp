#include <iostream>
#include <cstdio>

using namespace std;

int n;
pair <int, int> front[510], back[510];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);    
    int limit = n + (4 - n % 4) % 4;

    int num = 1;
    int size = limit / 4;
    front[1].second = num;
    num++;

    for (int i = 1; i <= size && num <= n; i++) {
        back[i].first = num;
        num++;

        if (num <= n) {
            back[i].second = num;
            num++;
        }
    }

    for (int i = size; i > 0 && num <= n; i--) {
        front[i].first = num;
        num++;

        if (num <= n) {
            front[i].second = num;
            num++;
        }
    }

    for (int i = 1; i <= size; i++) {
        printf("%d %d %d %d\n", i, 1, front[i].first, front[i].second);
        printf("%d %d %d %d\n", i, 2, back[i].first, back[i].second);
    }

    return 0;
}
