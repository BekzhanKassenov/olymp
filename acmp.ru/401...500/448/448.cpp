#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()

vector <int> primes;
bool prime[1500000];

void build() {
    memset(prime, true, sizeof prime);

    prime[0] = prime[1] = false;
    for (int i = 2; i < 1500000; i++) {
        if (prime[i]) {
            primes.push_back(i);

            if (1ll * i * i < 1500000) {
                for (int j = i * i; j < 1500000; j += i) {
                    prime[j] = false;
                }
            }
        }
    }
}

int n;
set <int> Set;
bool used[500010];
bool tused[500010];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        Set.insert(i);
    }

    build();

    for (size_t i = 0; Set.size() > 1u && i < primes.size(); i++) {
        vector <int> temp;

        int num = primes[i];

        for (set <int>::iterator it = Set.begin(); it != Set.end(); it++) {
            if (*it > num / 2) {
                break;
            }

            if (num - *it <= n && 2 * (*it) != num && !used[num - *it] && !tused[*it] && !tused[num - *it]) {
                printf("%d %d\n", *it, num - *it);
                temp.push_back(*it);
                temp.push_back(num - *it);

                tused[*it] = true;
                tused[num - *it] = true;
            }
        }

        for (vector <int>::iterator it = temp.begin(); it != temp.end(); it++) {
            Set.erase(*it);
            used[*it] = true;

            tused[*it] = false;
        }
    }

    return 0;
}
