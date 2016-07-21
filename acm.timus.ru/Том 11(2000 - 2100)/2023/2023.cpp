#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <string>

using namespace std;

vector <string> name[3] = {
    {"Alice", "Ariel", "Aurora", "Phil", "Peter", "Olaf", "Phoebus", "Ralph", "Robin"},
    {"Bambi", "Belle", "Bolt", "Mulan", "Mowgli", "Mickey", "Silver", "Simba", "Stitch"},
    {"Dumbo", "Genie", "Jiminy", "Kuzko", "Kida", "Kenai", "Tarzan", "Tiana", "Winnie"}
};

int getPos(const string& str) {
    for (int i = 0; i < 3; i++) {
        for (const auto& it: name[i]) {
            if (it == str) {
                return i;
            }
        }
    }

    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int pos = 0;
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int p = getPos(s);
        assert(p != -1);
        ans += abs(p - pos);
        pos = p;
    }

    cout << ans << endl;

    return 0;
}
