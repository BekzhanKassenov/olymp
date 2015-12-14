#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 5000010;

char s[MAXN], result[MAXN];
int pos;

struct Node {
    Node *next[2];
    Node *link;
    int len;

    Node* get_best() {
        if (pos - len - 1 >= 0 && s[pos - len - 1] == s[pos]) {
            return this;
        }

        return link->get_best();
    }
};

Node mem[MAXN];
Node *even, *odd, *cur;
int lastMem;

void init() {
    odd = &mem[0];
    odd->len = -1;
    odd->link = odd;

    even = &mem[1];
    even->len = 0;
    even->link = odd;

    lastMem = 2;
    cur = even;
}

bool addLetter() {
    Node *suffPal = cur->get_best();

    int c = s[pos] - 'a';
    if (suffPal->next[c] != NULL) {
        cur = suffPal->next[c];
        return false;
    }
    
    Node *nnode = &mem[lastMem++];
    suffPal->next[c] = nnode;
    nnode->len = suffPal->len + 2;
    
    if (nnode->len == 1) {
        nnode->link = even;
    } else {
        nnode->link = suffPal->link->get_best()->next[c];
    }

    cur = nnode;
    return true;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);

    init();
    for (pos = 0; s[pos]; pos++) {
        result[pos] = '0' + addLetter();
    }   

    puts(result);

    return 0;
}
