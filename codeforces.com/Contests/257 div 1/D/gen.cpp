#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    freopen("in", "w", stdout);

    vector <int> v;

    for (int i = 0; i < 20; i++) {
        v.push_back((1 << i) - 1);
        v.push_back(1 << i);
    }

    for (int i = 0; i < 500000; i++)
        v.push_back(rand());

    cout << v.size() << endl;

    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
}
