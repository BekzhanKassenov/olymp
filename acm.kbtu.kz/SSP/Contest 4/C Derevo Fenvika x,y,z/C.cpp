#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <vector <int> > > a;

int n;

void add(int val, int x, int y, int z)
{
    for (int i = x; i < n; i = i | (i + 1))
        for (int j = y; j < n; j = j | (j + 1))
            for (int k = z; k < n; k = k | (k + 1))
                a[i][j][k] += val; 
}

int sum(int x, int y, int z)
{
    int ans = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            for (int k = z; k >= 0; k = (k & (k + 1)) - 1)
                ans += a[i][j][k];
    return ans;
}

int sum(int x, int y, int z, int x2, int y2, int z2)
{
    int a = sum (x2, y2, z2);
    int b = sum (x - 1, y - 1, z - 1);
    int c = sum (x2, y2, z - 1) + sum (x2, y - 1, z2) + sum (x - 1 ,y2, z2);
    int d = sum (x - 1, y - 1, z2) + sum (x - 1, y2, z - 1) + sum (x2, y - 1, z - 1);
    int ans = a + b - c + d;
    return ans; 
}

int main()
{
    //freopen("input.txt","r",stdin);
    
    cin >> n;

    a.resize(n);

    for (int i = 0; i < n; i++)
        {
            a[i].resize(n);
            for (int j = 0; j < n; j++) 
                a[i][j].assign(n,0);
       }
    int x, y, z, x2, y2, z2;
    int k, val;
    for (;;)
        {   
            cin >> k;

            if (k==3)
                break;
            
            if (k==2)
                {
                    cin >> x >> y >> z >> x2 >> y2 >> z2;
                    cout << sum (x, y, z, x2, y2, z2) << endl;
                }
            
            if (k==1)
                {   
                    cin >> x >> y >> z >> val;
                    add (val, x, y, z);
                }
        }
    return 0;
}
