#include <stdio.h>
#include <string.h>

const int MAXN = 5000010;

char s[MAXN], res[MAXN];
int pos;

struct Node {
    Node *next[2];
    int len;
    Node *link;

    Node() : len (0), link (NULL) {
        memset(next, 0, sizeof next);
    }

    Node* get_best() {
        if (pos - len - 1 >= 0 && s[pos - len - 1] == s[pos]) {
            return this;
        }

        return link->get_best();
    }
};

Node mem[MAXN];
int last;

Node *odd, *even, *current;

void init() {
    odd = mem + last;
    last++;
    odd->len = -1;
    odd->link = odd;

    even = mem + last;
    last++;
    even->len = 0;
    even->link = odd;

    current = even;
}

bool add_letter() {
    Node *temp = current->get_best();
    int let = s[pos] - 'a';

    Node* next_ptr = temp->next[let];

    if (next_ptr == NULL) {
        next_ptr = mem + last;
        last++;
        
        next_ptr->len = temp->len + 2;
        temp->next[let] = next_ptr;

        if (next_ptr->len == 1) {
            next_ptr->link = even;
        } else {
            next_ptr->link = temp->link->get_best()->next[let];
        }

        current = next_ptr;

        return true;
    }

    current = next_ptr;
    return false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    gets(s);
    init();

    for (pos = 0; s[pos]; pos++) {
        res[pos] = '0' + add_letter();
    }

    puts(res);

    return 0;
}