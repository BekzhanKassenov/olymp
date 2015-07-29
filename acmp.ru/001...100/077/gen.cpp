#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    freopen("input.txt", "w", stdout);

    int n = rand() % 100000;

    int k = rand() % 3;

    cout << n << ' ' << k << endl;

    return 0;
}
