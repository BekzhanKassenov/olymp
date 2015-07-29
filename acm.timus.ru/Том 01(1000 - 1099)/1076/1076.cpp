#include <iostream>
#include <cstdio>

using namespace std;

int a[200][200];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
                cin >> a[i][j];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0, mx = 0;

        for (int j = 0; j < n; j++) {
            sum += a[i][j];
            mx = max(a[i][j], mx);
        }

        ans += sum - mx;
    }

    cout << ans;
    return 0;

}
