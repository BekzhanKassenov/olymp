/****************************************
**         Solution by NU #2           **
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

int base, n, mx;

vector <int> operator - (VI& s1, VI& s2) {
    VI res;
    
    for (int i = s1.size() - 1; i >= 0; i--) {
        int temp = s1[i] - s2[i];
        
        if (temp < 0) {
            temp += base;
            s1[i - 1]--;
        }
        
        res.push_back(temp);
    }
    
    while (!res.empty() && res.back() == 0)
        res.pop_back();
    
    if (res.empty())
        res.push_back(0);
        
    reverse(all(res));
    
    return res;
}

string make(const VI& a) {
    string res(all(a));
    
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] < 10)
            res[i] = a[i] + '0';
        else
            res[i] = a[i] + 'A' - 10;
    }   
    
    return res;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    cin >> base >> n;
    
    if (n == 1) {
        cout << "0";
        return 0;
    }
    
    vector <int> str1(n), str2(n);
    mx = base - 1;
    
    for (int i = 0; i < (n / 2); i++)
        str1[i] = mx;
    
    str1[n / 2] = 1;
    
    str2[0] = 1;
    
    for (int i = n - n / 2; i < n; i++)
        str2[i] = mx;
    
    
    //cout << make(str1) << ' ' << make(str2) << endl;    
    cout << make(str1 - str2) << endl;
    
    return 0;
}
