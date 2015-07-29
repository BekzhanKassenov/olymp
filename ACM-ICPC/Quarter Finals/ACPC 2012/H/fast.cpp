//Solution by Zhusupov Nurlan
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

typedef long long LL;
typedef map<string , int> MSI;
typedef vector<int> VI;

#define pb(x) push_back(x)
#define sqr(x) ((x) * (x))
#define SZ(t) ((int) t.size())
#define len(t) ((int) t.length())
#define base 10
#define fname ""
#define sz 1000 * 1000
#define EPS (1e-8)
#define MOD ((LL)1e9 + 7)
#define write(xx) printf("%d" , xx);
#define readln(xx) getline(cin , xx)
#define read(xx) scanf("%d" , &xx)
#define for(xx1 , yy1 , zz1) for(int zz1 = xx1 ; zz1 <= yy1 ; zz1++)

const double PI  = acos(-1.0);

LL T, n, k1, k2, N;
LL S, ans, s, t, res;
char c;

VI a, b;
bool was[sz];

LL gcd(LL a, LL b)
{
    LL c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

LL lcm(LL a, LL b)
{
    return a * b / gcd(a, b);
}

LL get(VI a)
{
    LL S = 1;

    if (a.size() > 0)
        for (0, a.size() - 1, i)
            S = lcm(a[i], S);   
   return S;
}

LL binpow(LL a, LL b)
{
    res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

LL divB(LL a, LL b)
{
    return (a * binpow(b, MOD - 2)) % MOD;      
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif  

    cin >> T;

    for (1, T, test)
    {
        cin >> n;
        S = 9;
        n = divB((9 * ((binpow(10, n) - 1 + MOD) % MOD)) % MOD, 9);
        a.clear();
        b.clear();
        for (1, 6, i)
        {
            was[i] = false;
            cin >> c;
            if (c == '0')
                b.pb(i);
            else
            if (c == '1')
                a.pb(i);
        }
        k1 = a.size();
        k2 = b.size();
        ans = (b.size() == 0);

        //1 - delitsia
        S = get(a);
        N = n;

        while (N % S != 0)
            {
                N--;
            }
                
        
        ans = (ans + divB(N, S)) % MOD;
        for (1, (1 << k2) - 1, mask)
        {               
            S = 1;
            t = 0;
            for (0, k2 - 1, i)
            {
                if (mask & (1 << i))
                {
                    t++;
                    S = lcm(S, b[i]);
                }
            }
            N = n;
            while (N % lcm(S, get(a)) != 0)
                N--;
            if (t & 1)
                ans = ((ans - divB(N, lcm(S, get(a)))) % MOD + MOD) % MOD;
            else
                ans = (ans + divB(N, lcm(S, get(a)))) % MOD;
        }
        cout << ans << endl;
    }
        return 0;
}