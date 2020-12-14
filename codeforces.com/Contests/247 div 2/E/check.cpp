#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

const double EPS = 1e-4;

bool cmp(double a, double b) {
    return abs(a - b) <= EPS;
}

int main() {
    ifstream str1("out1");
    ifstream str2("out2");

    double a, b;

    int cnt = 1;
    while ((str1 >> a) && (str2 >> b)) {
        if (!cmp(a, b)) {
            cout << "WA, line " << cnt << endl;
            return 1;
        }
        cnt++;
    }

    if ((str1 >> a) || (str2 >> b)) {
        cout << "WA lengths" << endl;
        return 1;
    }

    return 0;
}
