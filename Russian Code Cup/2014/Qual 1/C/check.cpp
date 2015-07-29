#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

const int maxn = 100010;

int a[maxn], d[maxn], temp[maxn], n, t;

int main() {
    ifstream input_file("in");
    ifstream answer("out");

    input_file >> t;

    while (t--) {
        input_file >> n;

        for (int i = 0; i < n; i++) {
            answer >> a[i];
        }

        for (int i = 0; i < n; i++) {
            d[i] = 1;

            for (int j = 0; j < i; j++)
                if (a[i] > a[j])
                    d[i] = max(d[i], d[j] + 1);
        }

        for (int i = 0; i < n; i++)
            input_file >> temp[i];

        bool correct = true;

        for (int i = 0; i < n; i++) {
            if (temp[i] != d[i])
                correct = false;
        }

        if (correct)
            cout << "OK" << endl;
        else
            cout << "WA" << endl;
    }

    return 0;
}
