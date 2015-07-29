#include <iostream>
#include <cassert>

using namespace std;

int get_intersection(int a, int b, int aa, int bb) {
    if (b < aa || bb < a) {
        return 0;
    }

    if (a <= aa && aa <= b && b <= bb) {
        return b - aa + 1;
    }

    if (aa <= a && a <= bb && bb <= b) {
        return bb - a + 1;
    }

    if (aa <= a && b <= bb) {
        return b - a + 1;
    }

    if (a <= aa && bb <= b) {
        return bb - aa + 1;
    }

    assert(false);
    return 0;
}

int main() {
    cout << get_intersection(0, 10, 5, 6) << endl;
    cout << get_intersection(5, 6, 0, 10) << endl;
    cout << get_intersection(0, 10, 0, 10) << endl;
    cout << get_intersection(0, 5, 4, 7) << endl;
    cout << get_intersection(4, 7, 0, 5) << endl;
    cout << get_intersection(0, 5, 5, 10) << endl;
    cout << get_intersection(5, 10, 0, 5) << endl;
    cout << get_intersection(0, 10, 100, 1111) << endl;
    return 0;
}