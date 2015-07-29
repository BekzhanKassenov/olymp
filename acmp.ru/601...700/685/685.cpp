#include <iostream>
#include <cstdio>

using namespace std;

void sort(int& a, int& b, int& c) {
    int mn = min(min(a, b), c);
    int mx = max(max(a, b), c);

    b = a + b + c - mn - mx;
    a = mx;
    c = mn;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, c;
    int aa, bb, cc;

    scanf("%d%d%d", &a, &b, &c);
    scanf("%d%d%d", &aa, &bb, &cc);

    sort(a, b, c);
    sort(aa, bb, cc);

    printf("%d", a * aa + b * bb + c * cc);

    return 0;
}
