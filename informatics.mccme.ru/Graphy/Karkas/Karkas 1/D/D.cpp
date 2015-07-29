#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    int n;
    
    cin >> n;

    vector <vector <int> > g(n, vector <int> (n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> g[i][j];

    vector <bool> nmb(n);

    int tmp;

    int ans1 = 0, ans2 = 0;

    for (int i = 0; i < n; i++)
        {
            cin >> tmp;

            nmb[i] = tmp;
        }

    tmp = 20000000;

    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                {
                    if (nmb[i] == 0 && nmb[j] == 1 && g[i][j] < tmp)
                        {
                            ans1 = i;
                            ans2 = j;
                            tmp = g[i][j];
                        }
                }
        }

    cout << ans1 + 1 << ' ' << ans2 + 1 << endl;
    
    return 0;
}
