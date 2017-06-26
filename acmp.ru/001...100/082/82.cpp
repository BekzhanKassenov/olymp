#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()

int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = read_int();
    int m = read_int();

    auto read_vec = [](int n) -> vector <int> {
        vector <int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = read_int();
        }

        sort(all(res));
        res.resize(unique(all(res)) - res.begin());
    
        return res;
    };

    vector <int> a(read_vec(n));
    vector <int> b(read_vec(m));

    for (int x : a) {
        if (binary_search(all(b), x)) {
            printf("%d ", x);
        }
    }

    puts("");
    return 0;
}
