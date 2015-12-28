#include <algorithm>
#include <cstdio>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }

struct Item {
    int a, b;
};

const int N = 10;

void print(Item arr[N]) {
    for (int i = 0; i < N; i++) {
        printf("(%d, %d)", arr[i].a, arr[i].b);

        if (i != N - 1) {
            printf(", ");
        } else {
            printf("\n");
        }
    }
}

int main() {
    Item arr[N];

    for (int i = 0; i < N; i++) {
        arr[i].a = i;
        arr[i].b = N - i;
    }


    sort(arr, arr + N, by(Item, a));
    print(arr);

    sort(arr, arr + N, by(Item, b));
    print(arr);

    return 0;
}
