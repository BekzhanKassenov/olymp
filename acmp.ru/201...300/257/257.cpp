#include <iostream>
#include <cstdio>

using namespace std;

long long a, b, c, d;
bool found;

long long cube(long long num) {
    return num * num * num;
}

long long sqr(long long num) {
    return num * num;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d);

    for (long long x = -100000; x <= 100000; x++) {
        if (a * cube(x) + b * sqr(x) + c * x + d == 0) {
            found = true;
            printf("%I64d ", x);
        }
    }

    if (!found) {
        puts("-1");
    } else {
        puts("");
    }

    return 0;
}
