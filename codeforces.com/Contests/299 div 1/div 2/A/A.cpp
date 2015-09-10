/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;

string int_to_words(int n) {
    static map <int, string> ones = {
                                      {0, "zero"}, 
                                      {1, "one"},
                                      {2, "two"},
                                      {3, "three"},
                                      {4, "four"},
                                      {5, "five"},
                                      {6, "six"},
                                      {7, "seven"},
                                      {8, "eight"},
                                      {9, "nine"},
                                    };

    static map <int, string> tens = {
                                      {0, ""},
                                      {1, "ten"},
                                      {2, "twenty"},
                                      {3, "thirty"},
                                      {4, "forty"},
                                      {5, "fifty"},
                                      {6, "sixty"},
                                      {7, "seventy"},
                                      {8, "eighty"},
                                      {9, "ninety"}
                                    };

    static map <int, string> others = {
                                        {11, "eleven"},
                                        {12, "twelve"},
                                        {13, "thirteen"},
                                        {14, "fourteen"},
                                        {15, "fifteen"},
                                        {16, "sixteen"},
                                        {17, "seventeen"},
                                        {18, "eighteen"},
                                        {19, "nineteen"},
                                      };

    if (n < 10) {
        return ones[n];
    }

    if (n % 10 == 0) {
        return tens[n / 10];
    }


    if (10 < n && n < 20) {
        return others[n];
    }

    return tens[n / 10] + "-" + ones[n % 10];
}   

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    puts(int_to_words(n).c_str());

    return 0;
}
