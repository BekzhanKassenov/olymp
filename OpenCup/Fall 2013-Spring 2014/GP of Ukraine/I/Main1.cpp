/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

typedef signed long long ll;

const ll maxn = (ll)1e6 + 10;
const ll base = (ll)1e6 + 4;
const ll par = base * base;

ll g[maxn];
ll n, l, r;

void set_first(int pos, ll first) {
    g[pos] += first * base * base;
}

ll get_first(int pos) {
    return g[pos] / base / base;
}

void set_second(int pos, ll second) {
    g[pos] += second * base;
}

ll get_second(int pos) {
    return (g[pos] / base) % base;
}

void set_parent(int pos, ll par) {
    g[pos] += par;
}

ll get_parent(int pos) {
    return g[pos] % base;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    scanf("%I64d", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%I64d%I64d", &l, &r);
        
        set_parent(l, i);
        set_parent(r, i);    
        
        set_first(l);
        set_second(r);
    }
    
    ll sum = 0;
    
    puts("DFS");
    
    ll cur = 1;
    ll level = 0;
    bool out = true;
    ll cnt = 0;

    while (cnt < n && cur != 0) {
        if (out) {
            cnt++;
            printf("%I64d\n", cur);
            sum += level;
        }
        
        ll fc = get_first(cur);
        if (fc != 0) {
            out = true;
            cur = fc;
            level++;
        } else {
            ll sc = g[cur] % base;
            if (sc != 0) {
                g[cur] -= sc;
                out = true;
                cur = sc;
                level++;
            } else {
                out = false;
                ll pr = g[cur] / par;
                
                cur = pr;
                level--;
            }
        } 
    }
    
    printf("%I64d", sum);
    
    return 0;
}
