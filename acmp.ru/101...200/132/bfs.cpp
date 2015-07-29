#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define INF 2000000000

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, s, f;

    cin >> n >> s >> f;

    vector <vector <int> > g(n, vector <int> (n));

    s--, f--;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    vector <int> d(n, INF);

    d[s] = 0;

    queue <int> q;

    q.push(s);

    while (!q.empty())
        {
            int v = q.front();
            q.pop();

            for (int i = 0; i < n; i++)
                {
                    if (g[v][i] > 0)
                        {
                            if (d[i] > d[v] + g[v][i])
                                {
                                    d[i] = d[v] + g[v][i];
                                    q.push(i);
                                }
                        }
                }
        }

    if (d[f] < INF)
        cout << d[f] << endl;
    else
        cout << -1;
    
    return 0;
}
