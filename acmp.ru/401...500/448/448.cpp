#include <cassert>
#include <vector>
#include <stdio.h>
#include <memory.h>
 
using namespace std;
 
#define all(x) (x).begin(), (x).end()
 
const int MAXN = 501000;
 
int n;
const int primes[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,
    107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223,
    227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347,
    349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
    467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607,
    613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701
};

bool prime[MAXN];

void generate() {
    memset(prime, true, sizeof(prime));
    for (int i = 0; i <= 701; i++) {
        prime[i] = false;
    }

    for (size_t i = 0; i < sizeof(primes) / sizeof(primes[0]); i++) {
        int p = primes[i];
        prime[p] = true;
        for (int j = p * p; j < MAXN; j += p) {
            prime[j] = false;
        }
    }
}

inline bool isprime(int n) {
    return prime[n];
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
 
    if (n == 2) {
        print(1, 2);
        return;
    }
 
    if (isprime(n)) {
        print(1, n - 1);
        return;
    }
     
    int nxt = n + !(n & 1);
    while (!isprime(nxt)) {
        nxt += 2;
    }
 
    int l = nxt - n;
    assert(l < n);

    print(l, n);
    solve(l - 1);
}
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    generate();

    scanf("%d", &n); 
 
    solve(n);
 
    return 0;
}
