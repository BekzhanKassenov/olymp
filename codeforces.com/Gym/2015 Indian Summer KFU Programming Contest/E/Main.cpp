/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node;

typedef Node* pNode;

enum ETYPE {
    OPEN,
    LETTER,
    CLOSE
}

struct Event {
    ETYPE type;
    int pos, num;
    char x, y;
};

pNode table[26][26];
char s[MAXN];
char ans[MAXN];
int n, m;

void add(char fr, char to, int num) {
    char ret = to;
    int diff = INF;

    int idxfr = fr - 'a';
    int idxto = to - 'a';
    for (int i = 0; i < 26; i++) {
        pNode temp = getBest(table[idxto][i], num);

        if (temp != NULL && temp.num - num < diff) {
            diff = temp.num - num;
            ret = temp.ret;
        }
    }

    pNode item = new Node(num, ret);
    table[idxfr][idxto].insert(item);
}

void erase(char fr, char to, int num) {

}

char getLetter(char old) {

}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    gets(s + 1);

    vector <Event> events;
    scanf("%d\n", &m);
    for (int i = 0; i < m; i++) {
        int l, r;
        char a, b;

        scanf("%d %d %c %c\n", &l, &r, &a, &b);

        events.push_back({OPEN, l, i, a, b});
        events.push_back({CLOSE, r, i, a, b});
    }

    for (int i = 1; i <= n; i++) {
        events.push_back({LETTER, i, 0, s[i], '\0'});
    }

    sort(all(events));

    for (const auto& event: events) {
        switch (event.type) {
            case OPEN:
                add(events[i].x, events[i].y, events[i].num);
                break;

            case CLOSE:
                erase(events[i].x, events[i].y, events[i].num);
                break;

            case LETTER:
                ans[events[i].pos] = getLetter(events[i].x);
                break;
        }
    }

    puts(ans + 1);
    
    return 0;
}
