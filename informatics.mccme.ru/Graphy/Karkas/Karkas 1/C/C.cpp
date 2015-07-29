#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector <int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int s, t;

    cin >> s >> t;

    s--, t--;

    int ans = a[s];

    for (int i = 0; i < n; i++)
        {   
            if (a[i] == ans)
                a[i] = a[t];
        }

    for (int i = 0; i <n; i++)
        cout << a[i] << ' ';
}
