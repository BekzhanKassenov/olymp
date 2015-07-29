#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <ctime>
#include <set>

using namespace std;

void print(FILE* f, double numb, const char* separator) {
    if (numb < 10) {
        fprintf(f, "%.3lf%s", numb, separator);
    } else {
        fprintf(f, "%.2lf%s", numb, separator);
    }
}


int main() {
    clock_t start = clock();

    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    ios_base :: sync_with_stdio(false);

    int n;

    cin >> n;

    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    v.resize(unique(v.begin(), v.end()) - v.begin());

    /*cout << v.size() << endl;

    for (vector <int> :: iterator it = v.begin(); it != v.end(); it++)
        cout << *it << ' ';*/

    freopen("log", "a", stderr);

    print(stderr, (clock() - start + .0) / CLOCKS_PER_SEC, "\n");

    v.clear();

    return 0;
}
