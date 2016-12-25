#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cassert>

using namespace std;

#define all(x) (x).begin(), (x).end()

const int MAXN = 210;

const char N = 'N';
const char S = 'S';
const char W = 'W';
const char E = 'E';

typedef pair <int, int> Pair;

char getLetter(const Pair& delta) {
    static map <Pair, char> Map = {
        {{-1,  0}, N},
        {{ 1,  0}, S},
        {{ 0, -1}, W},
        {{ 0,  1}, E}
    };

    return Map[delta];
}

Pair getDelta(char letter) {
    static map <char, Pair> Map = {
        {N, {-1,  0}},
        {S, { 1,  0}},
        {W, { 0, -1}},
        {E, { 0,  1}}
    };

    return Map[letter];
}

Pair& operator += (Pair& a, const Pair& b) {
    a.first += b.first;
    a.second += b.second;
    return a;
}

Pair& operator -= (Pair& a, const Pair& b) {
    a.first -= b.first;
    a.second -= b.second;
    return a;
}

char s[MAXN];
map <Pair, set <Pair> > g;
set <Pair> used;
map <Pair, char> par;
Pair start(0, 0);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(s);

    Pair cur(start);
    for (char c : s) {
        Pair temp(cur);
        temp += getDelta(c);
        g[cur].emplace(temp);
        g[temp].emplace(cur);
        cur = temp;
    }

    queue <Pair> q;
    q.push(cur);
    used.insert(cur);

    while (!q.empty()) {
        Pair v(q.front());
        q.pop();

        for (char dir : {N, E, S, W}) {
            Pair other(v);
            other += getDelta(dir);

            if (g[v].count(other) && !used.count(other)) {
                used.insert(other);
                par[other] = dir;
                q.push(other);
            }
        }
    }

    Pair temp(start);
    string ans;
    while (temp != cur) {
        char dir = par[temp];
        ans.push_back(dir);
        temp -= getDelta(dir);
    }

    reverse(all(ans));

    puts(ans.c_str());

    return 0;
}
