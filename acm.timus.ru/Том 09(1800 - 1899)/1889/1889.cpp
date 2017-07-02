#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

const string un = "unknown";

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    int n;
    cin >> n;

    vector <string> a(n);
    for (string& s : a) {
        cin >> s;
    }

    vector <int> ans;

    for (int lng = 1; lng <= n; lng++) {
        if (n % lng == 0) {
            bool ok = true;
            set <string> lngs;
            for (int i = 0; i < n; i += lng) {
                string s = un;
                for (int j = i; j < i + lng; j++) {
                    if (a[j] != un) {
                        if (s == un) {
                            s = a[j];
                        } else {
                            ok &= (s == a[j]);
                        }
                    }
                }

                if (s != un) {
                    if (lngs.count(s)) {
                        ok = false;
                    } else {
                        lngs.insert(s);
                    }
                }
            }

            if (ok) {
                ans.push_back(n / lng);
            }
        }
    }

    sort(ans.begin(), ans.end());

    if (ans.empty()) {
        cout << "Igor is wrong." << endl;
    } else {
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}