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
const int MAXN = 100050;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

string s;
int n, m;
int x, y;
vector <pair <int, int> > query[MAXN];
int par[MAXN], ans[MAXN];
vector <int> child[MAXN];
map <string, int> num;
int name[MAXN];

void merge(set <int>& a, set <int>& b) {
    if (a.size() < b.size())
        a.swap(b);

    for (set <int> :: iterator it = b.begin(); it != b.end(); it++)
        a.insert(*it);
}

void merge(deque <set <int> >& deq1, deque <set <int> >& deq2) {
    if (deq1.size() < deq2.size())
        deq1.swap(deq2);

    deque <set <int> > :: iterator it1 = deq1.begin();
    deque <set <int> > :: iterator it2 = deq2.begin();

    for (size_t i = 0; i < deq2.size(); i++) {
        merge(*it1, *it2);
        
        it1++;
        it2++;
    }
}

void dfs(int v, deque <set <int> >& q, int depth = 0) {
    deque <set <int> > temp;

    for (size_t i = 0; i < child[v].size(); i++) {
        dfs(child[v][i], temp, depth + 1);
        merge(q, temp);
        temp.clear();
    }

    set <int> tt;
    tt.insert(name[v]);
    q.push_front(tt);

    for (size_t i = 0; i < query[v].size(); i++) {
        int pos = query[v][i].second;
        int dst = query[v][i].first;

        if ((size_t) dst < q.size())
            ans[pos] = (*(q.begin() + dst)).size();
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif                                                    

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s >> par[i];

        if (!num.count(s)) {                                                            
            int nn = num.size();
            num[s] = nn;
        }

        name[i] = num[s];
        child[par[i]].push_back(i);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        query[x].push_back(make_pair(y, i));
    }

    deque <set <int> > temp;

    for (int i = 1; i <= n; i++)
        if (!par[i]) {
            temp.clear();
            dfs(i, temp);
        }

    for (int i = 0; i < m; i++)
        cout << ans[i] << endl;
    
    return 0;
}
