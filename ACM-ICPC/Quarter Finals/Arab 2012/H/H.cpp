/********************************************
***     Solution by Bekzhan Kassenov      ***
********************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define sqr(x) (x) * (x)
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define ll long long
#define ull unsigned long long
#define INF
#define MOD (1000 * 1000 * 1000 + 7)
#define EPS

long long powmod (long long n, long long s)
{
    if (s == 1)
        return n % MOD;
                
    if (s & 1)
        {
            long long tmp = n * powmod(n, s - 1) % MOD;
            return tmp;
        }

    else
        {
            long long tmp = powmod(n, s >> 1);

            tmp = (tmp * tmp) % MOD;

            return tmp;
        }   
}

long long divis(long long cnt, long long a)
{
    if (cnt == 1)
        {
            long long ans = 9 * a % MOD;
            return ans + 1;
        }

    long long s = powmod(9, MOD - 2);

    long long b1 = (9 * a) % MOD;

    long long m = powmod(10, cnt);

    m = (m - 1 + MOD) % MOD;

    long long ans = (((b1 * m) % MOD) * s) % MOD; 

    return ans;
}

long long gcd(long long a, long long b)
{
    if (a == 0 || b == 0)
        return a + b;


    if (a > b)
        return gcd(a % b, b);
    else
        return gcd(b % a, a);   
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    int t;

    cin >> t;

    string s;

    for (int j = 0; j < t; j++)
        {
            long long n;

            cin >> n >> s;

            long long sc1 = 1;

            for (int i = 0; i < 6; i++)
                {
                    if (s[i] == '1')
                        sc1 = lcm(sc1, i + 1);
                }

            long long ans = divis(n, powmod(sc1, MOD - 2));

            for (int mask = 1; mask < (1 << 6); mask++)
                {
                    int flag = -1;

                    int cnt = 0;

                    long long sc = 1;

                    for (int i = 0; i < 6; i++)
                        {
                            if (!(mask & (1 << i)))
                                continue;

                            if (s[i] == '0')
                                {
                                    cnt++;
                                    sc = lcm(sc, i + 1);
                                    flag = 1;
                                }

                            if (s[i] == '1')
                                {
                                    flag = 0;
                                    break;
                                }
                        }

                    if (flag != 1)
                        continue;

                    if (cnt % 2)
                        {
                            ans = (ans - divis(n,  powmod((sc1 * sc) % MOD, MOD - 2)) + MOD) % MOD;
                        }
                    else
                        {
                            ans = (ans + divis(n,  powmod((sc1 * sc) % MOD, MOD - 2)) ) % MOD;
                        }                       
                }
            cout << ans << endl;
        }

    return 0;
}
