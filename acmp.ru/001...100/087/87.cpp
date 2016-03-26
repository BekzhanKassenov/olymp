#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector <pair <int, string> > q;

bool equal(int i, int j, int k) {
    int leni = q[i].first;
    int lenj = q[j].first;
    int lenk = q[k].first;

    if (leni + lenj != lenk) {
        return false;
    }

    for (int ptr = 0; ptr < leni; ptr++) {
        if (q[i].second[ptr] != q[k].second[ptr]) {
            return false;
        }
    }

    for (int ptr = 0; ptr < lenj; ptr++) {
        if (q[j].second[ptr] != q[k].second[leni + ptr]) {
            return false;
        }
    }

    return true;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string s;

    for (;;) {   
        cin >> s;
        if (s == "ENDOFINPUT")
            break;
        q.push_back(make_pair(s.length(),s));
    }

    sort(q.begin(), q.end());

    int len = q.size();
    int ans = 0;
    bool t;
    for (int k = 0; k < len; k++) {
        t = false;

        for (int j = 0; j < k; j++) {
            for (int i = 0; i <= j && q[i].first + q[j].first <= q[k].first; i++) {
                t |= equal(i, j, k) || equal(j, i, k);
            }
        }

        ans += t;
    }

    cout << ans << endl;

    return 0;
}
