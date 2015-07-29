#include <stdio.h>
#include <string.h>

using namespace std;

const int MAXN = 200010;

int n;
char s[2][MAXN];
int idx, pos;

struct Node;

Node *even, *odd, *current;

struct Node {
    int cnt[2];
    Node *next[26];
    Node *link;
    int len;

    Node *get_best() {
        if (pos - len - 1 >= 0 && s[idx][pos - len - 1] == s[idx][pos]) {
            return this;
        }

        return link->get_best();
    }

    void attach(Node *parent, int let) {
        memset(cnt, 0, sizeof cnt);
        memset(next, 0, sizeof next);
        
        len = parent->len + 2;

        if (len == 1) {
            link = even;
        } else {
            link = parent->link->get_best()->next[let];
        }

        parent->next[let] = this;
    }

};

Node mem[2 * MAXN];
int lastNode = 0;
int x, y, z;

void init() {
    idx = 0;
    pos = 0;
    lastNode = 0;

    even = &mem[lastNode++];
    odd = &mem[lastNode++];

    even->len = 0;
    even->link = odd;
    memset(even->next, 0, sizeof(even->next));
    memset(even->cnt, 0, sizeof(even->cnt));

    odd->len = -1;
    odd->link = odd;
    memset(odd->next, 0, sizeof(odd->next));
    memset(odd->cnt, 0, sizeof(odd->cnt));

    current = even;
}

void add_letter() {
    Node *temp = current->get_best();
    int let = s[idx][pos] - 'a';

    if (temp->next[let] == NULL) {
        Node *child = &mem[lastNode++];
        child->attach(temp, let);
    }

    current = temp->next[let];
    current->cnt[idx]++;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++) {
        x = 0, y = 0, z = 0;

        gets(s[0]);
        gets(s[1]);

        init();

        for (idx = 0; idx < 2; idx++) {
            current = even;
            
            for (pos = 0; s[idx][pos]; pos++) {
                add_letter();
            }
        }

        for (int j = lastNode - 1; j > 1; j--) {
            if (mem[j].cnt[0] > mem[j].cnt[1]) {
                x++;
            } else if (mem[j].cnt[0] == mem[j].cnt[1] && mem[j].cnt[0] != 0) {
                y++;
            } else if (mem[j].cnt[0] < mem[j].cnt[1]) {
                z++;
            }

            mem[j].link->cnt[0] += mem[j].cnt[0];
            mem[j].link->cnt[1] += mem[j].cnt[1];
        }

        printf("Case #%d: %d %d %d\n", i, x, y, z);
    }
    
    return 0;
}
