#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

const char rus_letter[] = {'A', 'B', 'C', 'E', 
                      'H', 'K', 'M', 'O',
                      'P', 'T', 'X', 'Y', '\0'};

bool is_rus_letter(char c) {
    for (int i = 0; rus_letter[i]; i++)
        if (rus_letter[i] == c)
            return true;

    return false;
}

bool check(char s[]) {
    if (strlen(s) != 6)
        return false;

    return is_rus_letter(s[0]) && is_rus_letter(s[4]) && is_rus_letter(s[5]) &&
           isdigit(s[1]) && isdigit(s[2]) && isdigit(s[3]);
}

int n;
char s[60];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        gets(s);

        puts(check(s) ? "Yes" : "No");
    }

    return 0;
}
