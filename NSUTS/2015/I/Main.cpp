/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint32;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int Q;
uint32 a;

uint32 rev_add(uint32 h, int shift) {
    uint32 result = 0;
    
    uint32 mask = (1 << shift) - 1;
    uint32 cur = 0;

    while (mask > 0) {
        cur = h & mask;
        result |= cur;
        h -= cur;
        
        mask <<= shift;
        cur <<= shift;

        h -= cur;
    }

    return result;
}

uint32 rev_xor(uint32 h, int shift) {
    uint32 result = 0;
    
    uint32 mask = ((1 << shift) - 1) << (32 - shift);
    uint32 cur = 0;

    while (mask > 0) {
        cur = h & mask;
        result |= cur;
        h ^= cur;
        
        mask >>= shift;
        cur >>= shift;

        h ^= cur;
    }

    return result;
}

uint32 reverse(uint32 a) {
    a = rev_add(a, 16);
    a = rev_xor(a, 11);
    a = rev_add(a, 3);
    a = rev_xor(a, 6);
    a = rev_add(a, 10);

    return a;
}

uint32 gen() {
    uint32 result = rand();
    result <<= 16;
    result |= rand();

    return result;
}

void test() {
    while (true) {
        uint32 a = gen();
        int s = gen() % 31 + 1;

        uint32 aa1 = a + (a << s);
        uint32 aa2 = a ^ (a >> s);

        assert(rev_add(aa1, s) == a);
        assert(rev_xor(aa2, s) == a);
    }
}

int main() {
    srand(time(NULL));

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    //test();

    scanf("%d", &Q);

    while (Q--) {
        scanf("%u", &a);
        printf("%u\n", reverse(a));
    }

    return 0;
}
