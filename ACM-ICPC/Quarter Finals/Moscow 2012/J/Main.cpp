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
const int MAXN = 1010;
const int LIM = 10000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

// true if a < b
bool ask(int a, int b) {
    static char buf[10];
    //static int counter = 0;
    //counter++;
    //assert(counter <= LIM);

    cout << 1 << ' ' << a << ' ' << b << endl;

    cin >> buf;

    return strcmp(buf, "YES") == 0;
}


int n;

void add(vector <int>& a, vector <int>& x) {
    while (!x.empty()) {
        a.push_back(x.back());
        x.pop_back();
    }
}

void mergesort(vector <int>& a) {
    if (a.size() <= 1u) {
        return;
    }

    int half = a.size() / 2;

    vector <int> l(half), r(a.size() - half);

    for (int i = 0; i < half; i++) {
        l[i] = a[i];
    }

    for (int i = half; i < (int)a.size(); i++) {
        r[i - half] = a[i];
    }

    mergesort(l);
    mergesort(r);

    a.clear();

    while (!l.empty() && !r.empty()) {
        if (ask(l.back(), r.back())) {
            l.swap(r);
        }

        if (l.size() == 1u) {
            add(a, l);
            add(a, r);
            break;
        }

        int lsize = l.size();
        if (ask(l[lsize - 2], r.back())) {
            a.push_back(l.back());
            l.pop_back();

            a.push_back(r.back());
            r.pop_back();
            
        } else {
            a.push_back(l.back());
            l.pop_back();

            a.push_back(l.back());
            l.pop_back();
        }
    }

    add(a, l);
    add(a, r);

    reverse(all(a));
}

int main() {
#ifdef Local
//    freopen("in", "r", stdin);
#endif
    
    cin >> n;

    vector <int> a(n);

    for (int i = 1; i <= n; i++) {
        a[i - 1] = i;
    }   

    mergesort(a);

    //for (int i = 0; i + 1 < n; i++) {
      //  if (!ask(a[i], a[i + 1])) {
        //    cout << 0 << ' ';
          //  for (int i = 1; i <= n; i++) {
           //     cout << 1 << ' ';
            //}
            //cout << endl;
            //return 0;
        //}
    //}

    cout << 0;

    for (auto x: a) {
        cout << ' ' << x;
    }
    cout << endl;
    
    return 0;
}
