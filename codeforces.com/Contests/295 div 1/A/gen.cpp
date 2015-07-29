#include <bits/stdc++.h>

using namespace std;

char s[100010];
char let[] = {'A', 'C', 'G', 'T'};

int main() {
    srand(time(NULL));
    int n = ((rand() << 16) ^ rand()) % 100000 + 1;
    
    printf("%d\n", n);

    for (int i = 0; i < n; i++) {
        s[i] = let[rand() % 4];
    }

    puts(s);

    return 0;
}
    