#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

#define abs (x) (x < 0)?(-x):(x)
#define sqr(q) (q)*(q)
#define inf 1000000000
#define ll long long 

vector <vector <char> > used;

bool ch(int x, int y)
{
    if (used[x][y] && used[x + 1][y] && used[x + 2][y] &&
        used[x][y + 1] && used[x + 1][y + 1] && used[x + 2][y + 1] &&
        used[x][y + 2] && used[x + 1][y + 2] && used[x + 2][y + 2])
            return true;
    return false;
}

bool check(int x, int y)
{
    if (ch(x,y) || ch(x - 1, y) || ch(x - 2, y) ||
        ch(x, y - 1) || ch(x - 1, y - 1) || ch(x - 2, y - 1) ||
        ch(x, y - 2) || ch(x - 1, y - 2) || ch(x - 2, y - 2))
            return true;
    return false;
}

int main()
{
    int n,m;
    cin >> n >> m;
    int x,y;
    used.resize(n + 40);
    for (int i = 0; i < n + 40; i++)
        used[i].assign(n + 40, false);
    for (int i = 1; i <= m; i ++)
        {
            cin >> x >> y;
            x += 10;
            y += 10;
            used[x][y] = true;
            if (check(x,y))
                {
                    cout << i << endl;
                    return 0;
                }
        } 
    cout << -1;
    return 0;
}