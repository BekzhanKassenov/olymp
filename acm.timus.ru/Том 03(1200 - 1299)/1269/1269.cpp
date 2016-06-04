#include <cstring>
#include <cstdio>
#include <bitset>
#include <vector>

using namespace std;

typedef int node;
typedef unsigned char uchar;

const int INF = (int)1e9;
const int MAXN = 100 * 1024 + 10;
const node ROOT = 0;

#pragma pack(push, 1)
template <class T, class V>
class Pair {
public:
    T first;
    V second;

    Pair(T first = T(), V second = V()) : first(first), second(second) { }
};
#pragma pack(pop)

template <class Key, class Val>
class map {
  public:
    bool count(const Key& key) const {
        for (const auto& it: data) {
            if (it.first == key) {
                return true;
            }
        }

        return false;
    }

    Val& operator [] (const Key& key) {
        for (auto& it: data) {
            if (it.first == key) {
                return it.second;
            }
        }

        data.emplace_back(key, Val());

        if (data.capacity() > 256) {
            data.resize(256);
        }

        return data.back().second;
    }

    const Val& operator [] (const Key& key) const {
        for (const auto& it: data) {
            if (it.first == key) {
                return it.second;
            }
        }

        return Val(0);
    }
  private:
    vector <Pair <Key, Val> > data;
};

map <uchar, node> anext[MAXN]; // edges in automata
map <uchar, node> tnext[MAXN]; // edges in trie
node link[MAXN];
uchar parentChar[MAXN];
node parent[MAXN];
short len[MAXN];
int new_node = 1;

int n, m;

void addString() {
    node cur = ROOT;

    int l = 0;
    for (uchar c = getchar(); c != '\n'; c = getchar()) {
        if (!tnext[cur].count(c)) {
            tnext[cur][c] = new_node;

            link[new_node] = -1;
            parentChar[new_node] = c;
            parent[new_node] = cur;
            len[new_node] = -1;

            new_node++;
        }

        cur = tnext[cur][c];
        l++;
    }

    len[cur] = l;
}

node go(node cur, uchar c);
node getLink(node cur);

node go(node cur, uchar c) {
    if (anext[cur].count(c)) {
        return anext[cur][c];
    }

    if (tnext[cur].count(c)) {
        return anext[cur][c] = tnext[cur][c];
    }

    if (cur == ROOT) {
        return anext[cur][c] = ROOT;
    }

    return anext[cur][c] = go(getLink(cur), c);
}

node getLink(node cur) {
    if (link[cur] != -1) {
        return link[cur];
    }

    if (cur == ROOT || parent[cur] == ROOT) {
        return link[cur] = ROOT;
    }

    link[cur] = go(getLink(parent[cur]), parentChar[cur]);

    return link[cur];
}

short getLen(node cur) {
    if (len[cur] != -1) {
        return len[cur];
    }

    if (cur == ROOT) {
        return len[cur] = 0;
    }

    return len[cur] = getLen(getLink(cur));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        addString();
    }

    scanf("%d", &m);
    getchar();

    for (int i = 0; i < m; i++) {
        node cur = ROOT;

        int ans = INF;
        int c = getchar();
        for (int j = 0; c != '\n' && c != EOF; j++) {
            cur = go(cur, c);

            int l = getLen(cur);
            if (l != 0) {
                int pos = j - l + 1;
                ans = min(ans, pos);
            }
            
            c = getchar();
        }

        if (ans != INF) {
            printf("%d %d\n", i + 1, ans + 1);
            return 0;
        }
    }

    puts("Passed");

    return 0;
}
