#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()

const int INF = (int)1e9;

char s[110];
int n;
char word[50010][110];
char buf[110];
map <string, int> Map;

int dp[110];
int str[110];

char getDig(char c) {
    switch (c) {
        case 'i':
        case 'j':
            return '1';

        case 'a':
        case 'b':
        case 'c':
            return '2';

        case 'd':
        case 'e':
        case 'f':
            return '3';

        case 'g':
        case 'h':
            return '4';

        case 'k':
        case 'l':
            return '5';

        case 'm':
        case 'n':
            return '6';

        case 'p':
        case 'r':
        case 's':
            return '7';

        case 't':
        case 'u':
        case 'v':
            return '8';

        case 'w':
        case 'x':
        case 'y':
            return '9';

        case 'o':
        case 'q':
        case 'z':
            return '0';
    }

    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    while (true) {
        Map.clear();

        gets(s + 1);

        if (strcmp(s + 1, "-1") == 0) {
            break;
        }

        scanf("%d\n", &n);

        for (int i = 0; i < n; i++) {
            gets(word[i]);

            for (int j = 0; word[i][j]; j++) {
                buf[j] = getDig(word[i][j]);
                buf[j + 1] = '\0';
            }

            Map[string(buf)] = i;
        }

        // for (auto it: Map) {
        //     cerr << it.first << ' ' << it.second << endl;
        // }

        int len = strlen(s + 1);
        for (int i = 1; i <= len; i++) {
            dp[i] = INF;
            str[i] = 0;
        }

        dp[0] = 0;
        for (int i = 1; i <= len; i++) {
            for (int j = i - 1; j > max(i - 52, 0); j--) {
                for (int k = j; k <= i; k++) {
                    buf[k - j] = s[k];
                    buf[k - j + 1] = '\0';
                }

                int idx = -1;
                if (Map.count(string(buf))) {
                    idx = Map[string(buf)];
                }

                if (idx != -1 && dp[i] > dp[j - 1] + 1) {
                    dp[i] = dp[j - 1] + 1;
                    str[i] = idx;
                }
            }
        }

        if (dp[len] == INF) {
            puts("No solution.");
        } else {
            vector <int> idx;

            int pos = len;
            while (pos > 0) {
                idx.push_back(str[pos]);
                pos -= strlen(word[str[pos]]);
            }

            reverse(all(idx));
            for (int i: idx) {
                printf("%s ", word[i]);
            }

            puts("");
        }
    }

    return 0;
}
