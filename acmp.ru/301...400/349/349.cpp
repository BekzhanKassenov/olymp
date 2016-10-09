#include <stdio.h>
#include <vector>
 
using namespace std;
 
vector <int> primes;

bool prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
 
    return true;
}
 
int n, m;
bool found;
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    scanf("%d%d", &n, &m);

    for (int i = 2; i <= 1000; i++) {
        if (prime(i)) {
            primes.push_back(i);
        }
    }

    for (int i = n; i <= m; i++) {
        bool isPrime = true;
        for (size_t j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++) {
            if (i % primes[j] == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            printf("%d\n", i);
            found = true;
        }
    }
 
    if (!found) {
        puts("Absent");
    }
 
    return 0;
}