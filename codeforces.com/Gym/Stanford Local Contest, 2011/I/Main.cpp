/****************************************
**          Solution by NU #2          **
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
vector <double> st;
vector <string> vec;

double eval(double x) {
    st.clear();

    for (const string& str: vec) {
        if (str == "x") {
            st.push_back(x);
        } else if (str == "sin") {
            st.back() = sin(st.back());
        } else if (str == "cos") {
            st.back() = cos(st.back());
        } else if (str == "tan") {
            if (abs(cos(st.back())) < EPS) {
                return 0;
            }
            
            st.back() = tan(st.back());
        } else if (str == "+") {
            double a = st.back();
            st.pop_back();
            st.back() += a;
        } else if (str == "-") {
            double a = st.back();
            st.pop_back();
            st.back() -= a;
        } else if (str == "*") {
            double a = st.back();
            st.pop_back();
            st.back() *= a;
        } else {
            assert(false);
        }
    }

    return st.back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (cin >> n && n != 0) {
        vec.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        //vector <double> vals = {0, PI / 6.0, PI / 5.0, PI / 4.0, PI / 3.0, -PI / 6.0, -PI / 5.0, -PI / 4.0, -PI / 3.0};

        bool bad = false;
        for (double val = 0; val < 2 * PI; val += 0.001) {
            if (abs(eval(val)) > EPS) {
                cout << "Not an identity" << endl;
                bad = true;
                break;
            }
        }

        if (!bad) {
            cout << "Identity" << endl;
        }
    }
    
    return 0;
}
