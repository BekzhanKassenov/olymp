/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

inline ll gcd(ll a, ll b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }
    
    return a + b;
}

inline int sign(ll n) {
    return ((n > 0ll) - (n < 0ll));
}

class RealNumber {
public:
    RealNumber() : num(0), den(1) { }
    
    RealNumber(ll num) : num(num), den(1) { }
    
    RealNumber(ll num, ll den) : num(num), den(den) { 
        normalize();
    }
    
    RealNumber operator + (const RealNumber& rhs) const {
        RealNumber res(num * rhs.den + den * rhs.num, den * rhs.den);
        res.normalize();
        
        return res;
    }
    
    RealNumber operator - (const RealNumber& rhs) const {
        RealNumber res(num * rhs.den - den * rhs.num, den * rhs.den);
        res.normalize();
        
        return res;
    }
    
    RealNumber operator * (const RealNumber& rhs) const {
        RealNumber res(num * rhs.num, den * rhs.den);
        res.normalize();
        
        return res;
    }
    
    RealNumber operator / (const RealNumber& rhs) const {
        assert(rhs.num != 0);
        
        RealNumber res(num * rhs.den, den * rhs.num);
        res.normalize();
        
        return res;
    }
private:
    void normalize() {
        ll g = gcd(abs(num), abs(den));
        
        int sgn = sign(num) * sign(den);
        
        num /= g;
        den /= g;
        
        den = abs(den);
        num = abs(num) * sgn;
    }
    
    ll num, den;
};

class Point {
public:
    Point() : t(0), x(0), y(0) { }
    
    Point(int t, int x, int y) : t(t), x(x), y(y) { }
    
    Point(const Point& p) {
        *this = p;
    }
    
    Point operator + (const Point& p) const {
        return Point(t + p.t, x + p.x, y + p.y);
    }
    
    Point operator - (const Point& p) const {
        return Point(t - p.t, x - p.x, y - p.y);
    }
};

class Line {
public:

private:
    Point base, direction_vector;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    return 0;
}
