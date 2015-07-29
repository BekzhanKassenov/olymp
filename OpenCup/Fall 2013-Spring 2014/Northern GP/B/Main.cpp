/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "bayes"

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

int comp(double a, double b) {
    if (fabs(a - b) <= EPS)
        return 0;
    else if (a - b > 0)
        return 1;
     
    return -1;
}

double mind(double a, double b) {
    if (comp(a, b) == 1)
        return b;
        
    return a;
}

double maxd(double a, double b) {
    if (comp(a, b) == 1)
        return a;
        
    return b;
} 

const int maxn = 100010;

double a, b, alpha;
int n;
pair <double, double> parts[maxn], arr[maxn];
double parts_sum[maxn];
int parts_len;

bool get_int(const pair <double, double>& L, const pair <double, double>& R, pair <double, double>& res) {
    if (L.S > R.S) {
        if (comp(L.S, a) < 0 || comp(R.S, b) > 0)
            return false;
            
        res.F = (comp(L.S, b) <= 0 ? L.F : L.F + (b - L.S) * (R.F - L.F) / (R.S - L.S));
        res.S = (comp(R.S, a) >= 0 ? R.F : L.F + (a - L.S) * (R.F - L.F) / (R.S - L.S));
    } else {
        if (comp(L.S, b) > 0 || comp(R.S, a) < 0)
            return false;
            
        res.F = (comp(L.S, a) >= 0 ? L.F : L.F + (a - L.S) * (R.F - L.F) / (R.S - L.S));
        res.S = (comp(R.S, b) <= 0 ? R.F : L.F + (b - L.S) * (R.F - L.F) / (R.S - L.S));
    } 
    return true;
}

double fbin_search(int pos, int r) {
    double _left  = parts[r].F;
    double _right = parts[r].S;
    
    for (int i = 0; i < 50; i++) {
        double mid = (_left + _right) / 2;
        
        double sum = parts_sum[r - 1] - parts_sum[pos - 1] + (mid - parts[r].F);
        
        //cout << sum / parts_sum[parts_len] << ' ' << alpha << ' ' << mid << ' ' << pos << endl;
        
        if (comp(sum / parts_sum[parts_len], alpha) >= 0)
            _right = mid;
        else
            _left = mid;
    }
    return _right;
}

bool bin_search(int pos, double& res) {
    int _left  = pos;
    int _right = parts_len;
    
    while (_right - _left > 5) {
        int mid = (_left + _right) >> 1;
        
        if (comp((parts_sum[mid] - parts_sum[pos - 1]) / parts_sum[parts_len], alpha) >= 0)
            _right = mid;
        else
            _left = mid;
    }
    
    for (int i = _left; i <= _right; i++) {
        if (comp((parts_sum[i] - parts_sum[pos - 1]) / parts_sum[parts_len], alpha) >= 0) {
            res = fbin_search(pos, i);
            return true;
        }
    }
    
    return false;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    while (scanf("%d", &n) == 1 && n) {
        scanf("%lf%lf", &a, &b);
        scanf("%lf", &alpha);
        
        for (int i = 0; i < n + 1; i++) {
            scanf("%lf%lf", &arr[i].F, &arr[i].S);
        }
        
        parts_len = 0;
        
        pair <double, double> temp;
        
        for (int i = 0; i < n; i++) {
            if (get_int(arr[i], arr[i + 1], temp))
                parts[++parts_len] = temp;        
        }
        
        parts_sum[0] = 0.0;
        
        for (int i = 1; i <= parts_len; i++) {
            parts_sum[i] = parts[i].S - parts[i].F + parts_sum[i - 1];
        }
        
        double temp_r;
        double ans_l = 0, ans_r = 1e18;
        
        //cout << parts_len << endl;
        
        //for (int i = 1; i <= parts_len; i++)
        //    cout << parts[i].F << ' ' << parts[i].S << endl;
        
        //cout << endl;
        
        for (int i = 1; i <= parts_len; i++) {
            if (bin_search(i, temp_r) && comp(ans_r - ans_l, temp_r - parts[i].F) > 0) {
                ans_l = parts[i].F;
                ans_r = temp_r;
            }
        }
        
        printf("%.14lf %.14lf\n", ans_l, ans_r);
    }
    
    return 0;
}
