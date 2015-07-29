#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll lg(ll n)
{
    ll ans = 0;
    while ((1 << ans) < n)
        ans++;
    return ans;
}

vector <vector <ll> > sp;

ll get_ans(ll l, ll r)
{
    ll k = lg (r - l);
    if (l + (1 << k) > r && l!=r)
        k--;
    if (k < (l + r) / 2 && l!=r)
        k++;
    return min(sp[l][k] , sp[r - (1 << k) - 1] [k]);        
}

int main()
{
    freopen("input.txt","r",stdin);
    ll n,m,a,u,v;
    cin >> n >> m >> a;
    ll st = lg(n);
    sp.resize(n+2);
    
    for (ll i = 1; i <= n+1; i++)
        sp[i].assign(st+1,0);
    
    sp[1][0] = a;
    for (ll i = 2; i <= n; i++)    
        sp[i][0] = ((23 * (sp[i-1][0] % 16714589) + 21563) % 16714589);
    
    for (ll i = 1; i <= st + 1; i++)  
        for (ll j = 1; j <= n; j++)
            sp[j][i] = min(sp[j][i-1], sp[min((j+ ( 1 << (i - 1))), n)][i-1]);
    

    ll k = get_ans(min(u,v), max(u,v));

    cout << "OK" << endl;
    for (ll i=2;i<=m;i++)
        {
            u = ((((17 % n) * (u % n)) % n + (751 % n) + (k % n) + (2 * (i - 1)) % n) % n) + 1;
            v = ((((13 % n) * (v % n)) % n + (593 % n) + (k % n) + (5 * (i - 1)) % n) % n) + 1;
            k = get_ans(min(u,v),max(u,v));
        }
    cout << u << ' ' << v << ' ' << k;
    return 0; 
}
