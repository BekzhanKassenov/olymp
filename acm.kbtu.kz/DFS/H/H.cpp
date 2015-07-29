#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int s, p;

int u[4] = {1, 0, 0, -1};
int d[4] = {0, 1, -1, 0};

bool ok(int x, int y)
{
    if (x >= 0 && x < 6)
        if (y >= 0 && y < 6)
            return true;

    return false;
}

bool bfs(int sx, int sy, int a[6][6])
{
    queue <pair <int, int> > q;

    q.push(make_pair(sx, sy));

    int b[6][6] = {0};

    b[sx][sy] = 1;

    while (!q.empty())
        {
            pair <int, int> cur = q.front();

            q.pop();

            for (int i = 0; i < 4; i++)
                {
                    pair <int, int> tmp = cur;

                    tmp.first += u[i];
                    tmp.second += d[i];

                    if (ok(tmp.first, tmp.second))
                        {
                            if (b[tmp.first][tmp.second] == 0 && a[tmp.first][tmp.second] == 1)
                                {
                                    b[tmp.first][tmp.second] = 1;
                                    q.push(tmp);
                                }
                        }
                }
        }

    bool flag = 1;  

    for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
                flag &= (a[i][j] == b[i][j]);
        }

    return flag;
}

void check(int mask)
{
    if (__builtin_popcount(mask) != s)
        return;

    int a[6][6] = {0};

    int sx = -1, sy = -1;

    for (int i = 0; i < 16; i++)
        {
            int x = (i >> 2) + 1;
            int y = (i & 3) + 1;

            if (mask & (1 << i))
                {
                    a[x][y] = 1;
                    sx = x, sy = y;
                }
            else
                a[x][y] = 0;    
        }

    int cnt = 0;

    for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
                {
                    if (a[i][j] == 0)
                        {
                            for (int k = 0; k < 4; k++)
                                {
                                    int tmpx = i + d[k];
                                    int tmpy = j + u[k];

                                    if (tmpx >= 0 && tmpx < 6 && tmpy >= 0 && tmpy < 6) 
                                        if (a[tmpx][tmpy] == 1)
                                            cnt++;
                                }
                        }
                }
        }

    if (!bfs(sx, sy, a))
        return;

    if (cnt == p)
        {
            for (int i = 1; i <= 4; i++)
                {
                    for (int j = 1; j <= 4; j++)
                        if (a[i][j] == 1)
                            cout << '*';
                        else
                            cout << '.';

                    cout << endl;   
                }

            exit(0);    
        }
}

int main()
{
    freopen("h.in", "r", stdin);
    freopen("h.out", "w", stdout);

    cin >> p >> s;

    for (int mask = 0; mask < (1 << 16); mask++)
        check(mask);

    cout << "Impossible";

    return 0;
}
