#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("hardi.in", "r", stdin);
    freopen("hardi.out", "w", stdout);

    char c = getchar();
    int ans = c - '0';
    c = getchar();
    ans += (c - '0') * 7;
    c = getchar();
    ans += (c - '0') * 2;
    c = getchar();
    ans += (c - '0') * 9;

    cout << ans;
    return 0;
}
