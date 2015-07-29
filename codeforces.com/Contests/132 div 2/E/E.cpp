/*********************************************
**       Solution by Bekjan Kasenov         **
**********************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll l, r;
vector <int> divs[60];

int len(ll n) {
    int ans = 0;

    while (n) {
        ans++;
        n >>= 1;
    }

    return ans - 1;
}

void build() {
    for (int i = 1; i <= 60; i++) {
        for (int j = 2; j <= 30; j++) {
            if (i % j == 0)
                divs[i].push_back(j);
        }

        sort(all(divs[i]));
        divs[i].resize(unique(all(divs[i]) - divs[i].begin()));
    }
}

ll solve(ll n) {
    int k = len(n);

    for (int i = 0; i < divs[k].size(); i++) {
        ll t = n >> (
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%I64d%I64d", &l, &r);

    build();
    
    printf("%I64d", solve(r) - solve(l - 1));

    return 0;
}
