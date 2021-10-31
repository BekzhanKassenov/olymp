#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int a, b;
char res[10000];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d/%d", &a, &b);

    int predot = a / b;
    a %= b;

    vector <int> postdot;
    map <int, int> pos;

    while (a != 0 && !pos.count(a)) {
        pos[a] = postdot.size();
        cerr << a << endl;
        a *= 10;
        postdot.push_back(a / b);
        a %= b;
    }

    if (a == 0) {
        printf("%d", predot);
        if (!postdot.empty()) {
            putchar('.');
            for (auto x: postdot) {
                printf("%d", x);
            }
            puts("");
        }
        return 0;
    }

    printf("%d.", predot);
    size_t period = pos[a];
    for (size_t i = 0; i < period; i++) {
        printf("%d", postdot[i]);
    }
    putchar('(');
    for (size_t i = period; i < postdot.size(); i++) {
        printf("%d", postdot[i]);
    }
    putchar(')');
    puts("");

    return 0;
}
