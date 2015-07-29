#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    scanf("%d", &n);

    vector <int> a(n - 1);

    int f1;

    scanf("%d", &f1);

    int f2;

    bool flag = false;

    for (int i = 0; i < n - 1; i++)
        {
            scanf("%d", &f2);
            if (f2 > f1)
                a[i] = 1;
            else
                if (f2 < f1)
                    a[i] = -1;
                else
                    a[i] = 0;
            if (f2 != f1)
                flag = true;    

            f1 = f2;
        }

    int ans = 0;
    
    int tmp = 1;

    for (int i = 0; i < n - 1; i++)
        {
            if (i == 0 || a[i] != a[i - 1] && a[i] != 0 && a[i - 1] != 0)
                tmp ++;
            else
                {
                    ans = max(ans, tmp);
                    tmp = 2;
                }
            //cout << i << ' ' << tmp << endl;
        }

    ans = max(ans, tmp);    

    cout << ans;
    return 0;    
}

