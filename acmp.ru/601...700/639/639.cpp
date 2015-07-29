#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int n, k, last;
pair <double, string> a[2010];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k;

        for (int j = 0; j < k; j++) {
            cin >> a[last].first >> a[last].second;
            last++;
        }
    }

    sort(a, a + last);
    reverse(a, a + last);

    cout << last << endl;

    for (int i = 0; i < last; i++) {
        cout << fixed << setprecision(2) << a[i].first << ' ' << a[i].second << endl;
    }

    return 0;
}
