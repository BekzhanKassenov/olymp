#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;

    cin >> n;

    long long ans = 0;

    for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
                ans += i + j;
        }

    cout << ans;
    return 0;    
}