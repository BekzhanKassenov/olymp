#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 13;

char s[MAXN];
int p[MAXN], c[MAXN], cnt[26];

int main() {

    gets(s);

    int n = strlen(s), ce = 0, perm = 0;

    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            if (s[j] == 'a' + i) {
                c[j] = ce;
                p[perm++] = j;    
            }   
        }    
        ce++;
    }

    for (int i = 0; i < n; i++) {
        cout << c[i] << ' ';            
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;


    return 0;
}