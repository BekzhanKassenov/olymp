#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()

map <string, int> food;
vector <pair <int, string> > q;
char s[50], t[5]; 
int n, m, x, ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %s %s", &x, t, s);
        food[string(s)] = x;
    }

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %s %s", &x, t, s);
        q.push_back(MP(x, string(s)));
    }

    q.push_back(MP(0, ""));

    reverse(all(q));

    while (!q.empty() && (q.back().F != 0 || q.back().S != "")) {
        if (food[q.back().S] == 0 || food[q.back().S] >= q.back().F) {
            if (food[q.back().S])
                food[q.back().S] -= q.back().F;
            q.pop_back();
        } else {
            q.back().F = food[q.back().S];
            
            pair <int, string> temp = q.back();
            q.pop_back();
            
            pair <int, string> temp1 = q.back();
            q.pop_back();

            q.push_back(temp);
            q.push_back(temp1);                                     
        }
        ans++;
    }

    printf("%d", ans);

    return 0;
}
