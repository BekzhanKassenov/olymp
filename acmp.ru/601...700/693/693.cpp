#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

char s[55], t[55];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%s %s", s, t);

    for (int i = 0; s[i]; i++)
        s[i] = tolower(s[i]);

    for (int i = 0; t[i]; i++)
        t[i] = tolower(t[i]);
    
    sort(s, s + strlen(s));
    sort(t, t + strlen(t));
    
    puts(!strcmp(s, t) ? "Yes" : "No");

    return 0;
}
