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
#define File "bignim"

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

int a[1010];

map <multiset <int>, bool> mem;
map <multiset <int>, multiset <int> > next;

bool win(const multiset <int>& st) {
    if (mem.count(st))
        return mem[st];
        
    if (st.empty())
        return false;
        
    
    int nm = *(--st.end());
        
    for (int i = 1; i <= nm; i++) {
        int temp = nm - i;            
        
        multiset <int> nst(st);
            
        nst.erase(nst.find(nm));
            
        if (temp)
            nst.insert(temp);
                
        if (!win(nst)) {
            next[st] = nst;
            mem[st] = true;
            return true;
        }
    }
    
    mem[st] = false;
    return false;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    multiset <int> st(a, a + n);

    if (win(st)) {
        cout << "White wins";
    } else {
        cout << "Black wins";
    }
    
    while (next.count(st)) {
        for (multiset <int> :: iterator it = st.begin(); it != st.end(); it++)
            cerr << *it << ' ';
            
        cerr << endl;
        
        st = next[st];
    }
    
    for (multiset <int> :: iterator it = st.begin(); it != st.end(); it++)
        cerr << *it << ' ';
            
    cerr << endl;
    
    return 0;
}
