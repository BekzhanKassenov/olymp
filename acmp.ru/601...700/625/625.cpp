#include <iostream>
#include <cctype>
#include <cstdio>
#include <map>

using namespace std;

map <char, int> button;
map <char, int> cnt;
char let[11][30];
char msg[1010];
bool upper = true;
int ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 1; i <= 9; i++) {
        gets(let[i]);

        for (int j = 0; let[i][j]; j++) {
            button[let[i][j]] = i;
            cnt[let[i][j]] = j + 1;
        }
    }

    gets(msg);

    for (int i = 0; msg[i]; i++) {
        if (i > 0 && msg[i] != ' ' && button[msg[i]] == button[msg[i - 1]]) {
            ans++;
        }

        if (msg[i] == ' ') {
            ans++;
        } else {
            if (isalpha(msg[i])) {
                if (isupper(msg[i]) ^ upper) {
                    ans++;
                }
            
                first_cap = false;
            } else {
                first_cap = true;
            }

            ans += cnt[tolower(msg[i])];
        }

        cout << msg[i] << ' ' << ans << endl;
    }

    printf("%d\n", ans);

    return 0;
}