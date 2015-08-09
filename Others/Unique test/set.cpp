#include <iostream>
#include <cstdio>
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

    set <int> s;
    int x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    /*cout << s.size() << endl;

    for (set <int> :: iterator it = s.begin(); it != s.end(); it++)
        cout << *it << ' ';*/

    freopen("log", "a", stderr);

    print(stderr, (clock() - start + .0) / CLOCKS_PER_SEC, "   ");

    s.clear();

    return 0;
}