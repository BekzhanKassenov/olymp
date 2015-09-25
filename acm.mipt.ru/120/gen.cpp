#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;

#define all(x) (x).begin(), (x).end()

const int MAXC = 100000;

int main() {
	srand(time(NULL));

    int n = rand() % 20000 + 1;

    vector <int> vec;

    for (int i = 0; i < n; i++) {
        int type = rand() % 3;

        if (type == 0) {
            printf("ADD %d %d\n", rand() % MAXC, rand() % MAXC);
        } else if (type == 1) {
            int x = rand() % MAXC;
            int xx = x + rand() % MAXC;
            int y = rand() % MAXC;
            int yy = y + rand() % MAXC;

            printf("COUNT %d %d %d %d\n", x, y, xx, yy);
        } else {
            printf("DELETE %d %d\n", rand() % MAXC, rand() % MAXC);
        }
    }
    return 0;
}
