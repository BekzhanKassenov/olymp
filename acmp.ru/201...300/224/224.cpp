#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end());

    vector <long long> vec;
    for (int i = 0; i < 3 && !a.empty(); i++) {
        vec.push_back(a.back());
        a.pop_back();
    }

    for (int i = 0; i < min(3, (int)a.size()); i++) {
        vec.push_back(a[i]);
    }

    long long ans = -1e18;
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = i + 1; j < vec.size(); j++) {
            for (size_t k = j + 1; k < vec.size(); k++) {
                ans = max(ans, vec[i] * vec[j] * vec[k]);
            }
        }
    }

    printf("%I64d\n", ans);

    return 0;
}
