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

    for (int i = 0; i < n; i++)
        cout << rand() + 1 << ' ';

    cout << endl;

    return 0;
}
