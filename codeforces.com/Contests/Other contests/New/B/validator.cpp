#include "testlib.h"

using namespace std;

const int MAXN = 100000;
const int MAXK = 100000;
const int MAXNUMBER = 1000 * 1000 * 1000;

int main() {
    registerValidation();

    int n = inf.readInt(1, MAXN, "n");
    inf.readSpace();

    inf.readInt(1, MAXK, "k");
    inf.readEoln();

    for (int i = 0; i < n; i++) {
        inf.readInt(1, MAXNUMBER, "a_i");

        if (i == n - 1) {
            inf.readEoln();
        } else {
            inf.readSpace();
        }
    }

    inf.readEof();

    return 0;
}
