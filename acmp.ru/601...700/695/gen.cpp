#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("input.txt", "w", stdout);

    for (char a1 = 'A'; a1 <= 'I'; a1++) {
        for (char a2 = '1'; a2 <= '9'; a2++) {
            for (char a3 = 'A'; a3 <= 'I'; a3++) {
                for (char a4 = '1'; a4 <= '9'; a4++) {
                    printf("%c%c %c%c\n", a1, a2, a3, a4);
                }
            }
        }
    }

    return 0;
}
