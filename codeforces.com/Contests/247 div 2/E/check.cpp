#include <fstream>
#include <cmath>

using namespace std;

const double EPS = 1e-4;

bool cmp(double a, double b) {
    return abs(a - b) <= EPS;
}

int main() {
    ifstream str1("out1");
    ifstream str2("out2");

    double a, b;

    while ((str1 >> a) && (str2 >> b)) {
        if (!cmp(a, b))
            return 1;
    }

    if (!str1.eof() || !str2.eof())
        return 1;

    return 2;
}
