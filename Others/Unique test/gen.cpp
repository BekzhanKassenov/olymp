#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

int get_random_number() {
    return (rand() << 16) + rand();
}

int main() {
    ios_base :: sync_with_stdio(false);

    freopen("in", "w", stdout);

    int n = 10000000;

    stringstream ss;

    ss << n << endl;

    for (int i = 0; i < n; i++)
        ss << get_random_number() << ' ';

    ss << endl;

    cout << ss.str();

    return 0;   
}