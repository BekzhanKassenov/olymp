#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
char s[17000];
bool flag = true;
int type, ans;
bool cnt;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (gets(s), n = strlen(s); flag; gets(s), n = strlen(s)) {

        for (int i = 0; i < n && type != 1; i++) {
            cnt ^= (s[i] == '\'');
            
            if (cnt)
                continue;

            if (!type) {
                if (i < n - 1) {
                    if (s[i] == '/' && s[i + 1] == '/')
                        type = 1;
                    else if (s[i] == '(' && s[i + 1] == '*')
                        type = 2;
                }

                if (!type && s[i] == '{')
                    type = 3;
            } else {
                if (i < n - 1 && s[i] == '*' && s[i + 1] == ')' && type == 2)
                    type = 0, ans++;
                else if (s[i] == '}' && type == 3)
                    type = 0, ans++;
            }
        }

        if (type == 1)
            type = 0, ans++;

        flag = !feof(stdin);
    }

    printf("%d\n", ans);

    return 0;
}