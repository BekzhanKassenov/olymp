#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

#define F first
#define S second

int n, m;
pair <char, char> a[40], b[5];
char s[] = "6789TJQKA", R;
map <char, int> pos;
bool used[40];

bool cmp(const pair <char, char>& a, const pair <char, char>& b) {
    if (a.S == b.S)
        return pos[a.first] > pos[b.first];

    if (a.S == R)
        return true;

    return false;
}

bool go(int pos) {
    if (pos == m)
        return true;

    bool res = false;

    for (int i = 0; i < n && !res; i++) {
        if (!used[i] && cmp(a[i], b[pos])) {
            used[i] = true;
            res |= go(pos + 1);
            used[i] = false;
        }
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 9; i++)
        pos[s[i]] = i;         
    
    scanf("%d %d %c\n", &n, &m, &R);

    for (int i = 0; i < n; i++) {
        scanf("%c%c ", &a[i].first, &a[i].second);
    }

    for (int i = 0; i < m; i++) {
        scanf("\n%c%c ", &b[i].first, &b[i].second);
    }

    puts(go(0) ? "YES" : "NO");

    return 0;
}