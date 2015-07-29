#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int n;
vector <vector <double> > a;

void REF(vector <vector <double> >& a) {
    for (int i = 0; i < n; i++) {
        int mx = i;

        for (int j = i + 1; j < n; j++) {
            if (abs(a[mx][i]) < abs(a[j][i]))
                mx = j;
        }

        a[i].swap(a[mx]);

        for (int j = i + 1; j < n; j++) {
            double mul = -a[j][i] / a[i][i];

            for (int k = i; k < n + 1; k++) {
                if (k == n) {
                    cout << i << ' ' << j << ' ' << a[i][k] << ' ' << mul << ' ' << a[i][k] * mul << endl;
                }
                a[j][k] += a[i][k] * mul;
            }   
        }
    }
}

void back_stage(vector <vector <double> >& a) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            double mul = -a[j][i] / a[i][i];

            for (int k = i; k < n + 1; k++)
                a[j][k] += a[i][k] * mul;
        }

        a[i][n] /= a[i][i];
        a[i][i] = 1;
    }
}

int sign(double n) {
    return (n > 0) - (n < 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    a.assign(n, vector <double> (n + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    REF(a);
    
    back_stage(a);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++)
            printf("%4.2lf ", a[i][j]);
        puts("");
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", (int) (a[i][n] + sign(a[i][n]) * .5));
    }
    
    return 0;
}
