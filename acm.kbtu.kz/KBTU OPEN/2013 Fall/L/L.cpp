/******************************************
**          Solution by NU #2            **
******************************************/

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define MP make_pair
#define File "substrings"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;
typedef complex <double> cd;
typedef vector <cd> vcd;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double PI = acos(-1.0);

template <typename T>
inline T sqr(T x) {
    return (x * x);
}

cd w[(int)(8 * 1e6 + 10)];

int nn = 1;

int rev(int i, int l) {
    int tp = 0;
    for (int j = 0; j < l; ++j){
        if (i&(1<<j))
            tp += (1 << (l - j - 1));
    }
    return tp;
}

void fft(vcd & P, int len) {
int k = 0;
    while ((1<<k) <= len)
        k++;
    k--;
    for (int i = 0; i < len; ++i) {
        if (i < rev(i, k))
            swap(P[i], P[rev(i, k)]);
            //cout << k << " " << i << " " << rev(i, k) << endl;
            }
    if (len == 1)            
        return;
    for (int i = 1; i < len; i <<= 1){
        for (int j = 0; j < len; j += i*2){
            for (int k = 0; k < i; ++k){
                cd u = P[j+k];
                cd v = P[j+k+i];

                P[j + k] = u + v * w[nn/i/2*k];
                P[j + k + i] = u - v * w[nn/i/2*k];
            }
        }
    }                                                           
}                                                            

int d[1000000];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n;
    cin >> n;
    
    string str;
    cin >> str;
    
    for (int i = 0; i < n; ++i)
        d[i + 1] = d[i] + (str[i] - '0');
    
    while (nn < d[n])
        nn <<= 1;

    nn <<= 1;
    for (int i = 0; i < nn; i++)
        w[i] = cd(cos(2.0 * PI / nn * i), sin(2.0 * PI / nn * i));

    vcd a(nn);
    vcd b(nn);

    for (int i = 0; i <= n; ++i){
        a[d[i]] = 1;
    }
    
    for (int j = 0; j <= n; ++j){
        b[d[n] - d[n-j]] = 1;
    }

    fft(a, nn);
    fft(b, nn);
    
    for (int i = 0; i < nn; ++i)
        a[i] *= b[i];
    
    fft(a, nn);
    
    reverse(a.begin() + 1, a.end());
    
    for (int i = 0; i < nn; ++i)
        a[i] /= nn;
    
    int ans = 0;
    
    for (int i = d[n]; i < d[n]*2; ++i){
        int tp = (int)(a[i].real() + 0.5);
//      cout << tp << " " << i << endl;
        if (tp > 0)
            ans++;
    }
//  cout << endl;
    cout << ans;
    return 0;

}
