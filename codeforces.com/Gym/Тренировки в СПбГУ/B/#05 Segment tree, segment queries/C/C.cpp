#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

struct ver
{
    long long sum;
    
    int flag;

    ver() : sum(0), flag(-1) {}

}t[1000000];

void push(int v, int l, int r)
{
    if (t[v].flag != -1)
        {
            t[v].sum = (r - l + 1) * 1ll * t[v].flag;
            t[v << 1].flag = t[(v << 1) + 1].flag = t[v].flag;
            t[v].flag = -1;
        }
}

void upd(int v, int l, int r, int zl, int zr, int val)
{
    if (l > r)
        return;

    push(v, l, r);

    //cerr << "ver " << v << ' ' << l << ' ' << r << endl;

    if (l > zr || r < zl)
        return;

    if (l == r)
        {
            if (l >= zl && l <= zr)
                {
                    t[v].flag = val;
                    t[v].sum = val;
                }

            return; 
        }

    if (l >= zl && r <= zr)
        {
            t[v].flag = val;
            t[v].sum = (r - l + 1) * 1ll * val;
            return;
        }


    int m = (l + r) >> 1;

    upd((v << 1),     l,       m,  zl, zr, val);
    upd((v << 1) + 1, m + 1,   r,  zl, zr, val);

    push((v << 1), l, m);
    push((v << 1) + 1, m + 1, r);

    t[v].sum = t[v << 1].sum + t[(v << 1) + 1].sum;
}

long long sum(int v, int l, int r, int zl, int zr)
{
    if (l > r)      
        return 0;

    push(v, l, r);

    if (l > zr || r < zl)
        return 0;

    if (l == r)
        {
            if (l >= zl && r <= zr)
                return t[v].sum;
            else
                return 0;
        }

    if (l >= zl && r <= zr)
        return t[v].sum;  

    int m = (l + r) >> 1;

    push((v << 1), l, m);
    push((v << 1) + 1, m + 1, r);

    return (sum(v << 1, l, m, zl, zr) + sum((v << 1) + 1, m + 1, r, zl, zr));
}

int main()
{
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    //freopen("tmp", "w", stderr);

    ios_base :: sync_with_stdio(false);

    int n, m;

    cin >> n >> m;

    char c;

    for (int i = 0; i < m; i++)
        {
            cin >> c;
            
            if (c == 'A')
                {
                    int l, r, x;
                    
                    cin >> l >> r >> x;

                    l--, r--;

                    //cerr << "UPD" << endl;

                    upd(1, 0, n - 1, l, r, x);

                    /*for (int i = 1; i <= 3; i++)
                        {
                            cerr << "vertex " << i << ' ' << t[i].flag << " sum = " << t[i].sum << endl;
                        }

                    cerr << endl;*/ 
                }
            else
                {
                    int l, r;

                    cin >> l >> r;

                    l--, r--;

                    cout << sum(1, 0, n - 1, l, r) << endl;
                }   
        }

    return 0;
}
