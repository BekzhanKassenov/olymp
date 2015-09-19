#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define all(x) (x).begin(), (x).end()

const int MAXN = 1000010;

bool prime[MAXN];
int n;

void sieve() {
    memset(prime, true, sizeof prime);

    prime[0] = prime[1] = false;
    for (int i = 4; i < MAXN; i += 2) {
        prime[i] = false;
    }
    
    for (int i = 3; i * i < MAXN; i += 2) {
        if (prime[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                prime[j] = false;
            }
        }
    }
}

void print(int l, int r) {
    while (l < r) {
        printf("%d %d\n", l, r);
        l++, r--;
    }
}

void solve(int n) {
    if (n <= 1) {
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if ((i & 1) != (n & 1) && prime[n + i]) {
            print(i, n);
            solve(i - 1);
            return;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    sieve();

    scanf("%d", &n);
    
    solve(n);
    
    return 0;
}

