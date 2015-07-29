#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    int n;

    cin >> n;

    string s;

    getline(cin, s);

    map <string, bool> used;

    int ans = 0;

    for (int i = 0; i < n; i++)
        {
            getline(cin, s);

            if (used[s])
                ans++;

            used[s] = true;
        }

    cout << ans;    
}   
