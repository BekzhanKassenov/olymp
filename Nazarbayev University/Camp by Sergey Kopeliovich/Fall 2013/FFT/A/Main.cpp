#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()

struct my_complex {
private:
    double x, y;

public:
    my_complex() : x(0), y(0) {}

    my_complex(double x, double y) : x(x), y(y) {}

    my_complex(const my_complex& a) : x(a.x), y(a.y) {}

    my_complex(char c) : x(double(c - '0')), y(0) {}

    my_complex operator + (const my_complex& a) const {
        return my_complex(x + a.x, y + a.y);
    }

    my_complex operator * (const my_complex& a) const {
        return my_complex(x * a.x - y * a.y, y * a.x + x * a.y);
    }

    void operator /= (double a) {
        x /= a;
        y /= a;
    }

    void operator *= (const my_complex& a) {
        double tx = x * a.x - y * a.y;
        double ty = y * a.x + x * a.y;
        x = tx, y = ty;
    }

    double& real() {
        return x;
    }

    double& imag() {
        return y;
    }
};

typedef my_complex nmb;

const double PI = acos(-1.0);

vector <nmb> prec;

int n;

void fft(vector <nmb>& P, int len) {
    if (len == 1)
        return;

    vector <nmb> A(len >> 1), B(len >> 1);

    for (int i = 0; i < len; i += 2) {
        A[i >> 1] = P[i];
        B[i >> 1] = P[i + 1];
    }

    int nlen = len >> 1;

    fft(A, nlen);
    fft(B, nlen);
    
    for (int i = 0; i < len; i++)
        P[i] = A[i % nlen] + prec[i * (n / len)] * B[i % nlen];
}

int main() {
    freopen("mul.in", "r", stdin);
    freopen("mul.out", "w", stdout);

    ios_base :: sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    vector <nmb> a(all(s)), b(all(t));
    
    n = 1;
    while (n < (int)max(a.size(), b.size()))
        n <<= 1;
    n <<= 1;
    
    prec.resize(n);

    double ang = 2 * PI / (n + .0);
    for (int i = 0; i < n; i++) 
        prec[i] = nmb(cos(ang * i), sin(ang * i));
    
    reverse(all(a));
    reverse(all(b));

    a.resize(n);
    b.resize(n);

    fft(a, n);
    fft(b, n);

    for (int i = 0; i < n; i++)
        a[i] *= b[i];

    fft(a, n);

    reverse(a.begin() + 1, a.end());

    for (int i = 0; i < n; i++)
        a[i] /= (n + .0);

    vector <int> res(n);
    int carry = 0;
    for (int i = 0; i < n; i++) {
        carry += (int)(a[i].real() + .5);
        res[i] = carry % 10;
        carry /= 10;
    }

    while (!res.empty() && res.back() == 0)
        res.pop_back();

    if (res.empty())
        res.push_back(0);

    reverse(all(res));  

    for (size_t i = 0; i < res.size(); i++)
        cout << res[i];

    return 0;
}