#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    freopen("in", "w", stdout);
    srand(time(NULL));
    int n = rand() % 10000 + 1;

    cout << n << endl;

    for (int i = 0; i < n; i++)  {
        int l = rand() + 1;
        int r = l + rand();

        cout << l << ' ' << r << endl;
    }

    return 0;
}
