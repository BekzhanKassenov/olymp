#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>

using namespace std;

const double PI = acos(-1.0);

int main() {
    int n;

    cin >> n;

    /*if (n == 10) {
        int k = 0;
     
        while (true) {
            k += sqrt(k + 100500);
        }
    }   */
    
    switch (n) {
        case 1:
            cout << 1;
            break;
        case 2:
            cout << 2;
            break;
        case 3:
            printf("%.9lf", (2 / sqrt(3) + 1));
            break;
        case 4:
            printf("%.9lf", (1 + sqrt(2)));
            break;
        case 5:
            printf("%.9lf", 1.0 / sin(PI / 5.0) + 1.0);
            break;
        case 6:
            cout << 3;
            break;
        case 7:
            printf("%.9lf", 1.0/sin(PI / 7.0) + 1.0);
            break;
        case 8:
            printf("%.9lf", 1.0/sin(PI / 8.0) + 1.0);
            break;
        case 9:
            printf("%.9lf", 1.0/sin(PI / 9.0) + 1.0);
            break;
        case 10:
            printf("%.9lf", 1.0/sin(PI / 10.0) + 1.0);
            break;                          
    }

    return 0;
}
