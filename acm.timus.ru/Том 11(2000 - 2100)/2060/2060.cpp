#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 300010;

char s[MAXN];
int pos, N;

struct Node;

Node *even, *odd;

struct Node {
    Node *next[26];
    Node *link;
    int len;
    int height;

    //static Node *even, *odd;

    void init(Node &parent, int let) {
        memset(next, 0, sizeof next);

        parent.next[let] = this;
        len = parent.len + 2;

        if (len == 1) {
            link = even;
        } else {
            link = parent.link->get_best()->next[let];
        }

        height = link->height + 1;
    }

    Node *get_best() {
        if (pos - len - 1 >= 0 && s[pos - len - 1] == s[pos]) {
            return this;
        }

        return link->get_best();
    }
};

int lastNode;
Node mem[MAXN];
int ans_l[MAXN], ans_r[MAXN];
Node *current;
long long ans;

void init() {
    pos = 0;
    lastNode = 0;

    even = &mem[lastNode++];
    odd = &mem[lastNode++];

    even->height = 0;
    even->len = 0;
    even->link = odd;

    odd->height = 0;
    odd->len = -1;
    odd->link = odd;

    current = even;

    //Node::even = even;
    //Node::odd = odd;
}

void addLetter() {
    Node *temp = current->get_best();
    int let = s[pos] - 'a';

    if (temp->next[let] == NULL) {
        Node *newNode = &mem[lastNode++];

        newNode->init(*temp, let);
    }

    current = temp->next[let];
    pos++;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    N = strlen(s);

    init();

    for (int i = 0; i < N; i++) {
        addLetter();
        ans_l[i] = current->height;
    }

    init();
    reverse(s, s + N);

    for (int i = 0; i < N; i++) {
        addLetter();
        ans_r[i] = current->height;
    }

    reverse(ans_r, ans_r + N);

    for (int i = 0; i + 1 < N; i++) {
        ans += 1ll * ans_l[i] * ans_r[i + 1];
    }

    printf("%I64d\n", ans);

    return 0;
}
