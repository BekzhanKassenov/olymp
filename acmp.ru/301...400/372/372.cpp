#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

char s[20], arr[2] = {'(', '['};
stack <char> stck;
int n, cnt;

char pair_for(char c) {
    if (c == '(')
        return ')';
    else if (c == '[')
        return ']';
    else if (c == ')')
        return '(';

    return '[';
}

void gen(int pos) {
    if (pos == n) {
        s[pos] = '\0';
        printf("%s\n", s);
        return;   
    }

    if (!stck.empty()) {
        s[pos] = pair_for(stck.top());
        stck.pop();
        gen(pos + 1);
        stck.push(pair_for(s[pos]));
    }

    if (cnt < n / 2) {
        for (int i = 0; i < 2; i++) {
            stck.push(arr[i]);
            s[pos] = arr[i];
            cnt++;
            gen(pos + 1);
            cnt--;
            stck.pop();
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;

    gen(0);

    return 0;
}
   