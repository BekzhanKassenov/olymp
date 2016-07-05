#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 5010;

using uint = unsigned int;
using ulong = unsigned long long;

struct LongInt {
    ulong first, second;

    LongInt(ulong first, ulong second) : first(first), second(second) {}

    LongInt(ulong num) : LongInt(0, num) {}

    LongInt(uint a = 0, uint b = 0, uint c = 0, uint d = 0) :
        LongInt((ulong(a) << 32) ^ b, (ulong(c) << 32) ^ d) {}
};

LongInt operator << (const LongInt& num, int shift) {
    if (shift >= 128) {
        return LongInt();
    }

    if (shift >= 64) {
        return LongInt(num.second << (shift - 64), 0);
    }

    ulong first = (num.first << shift) | (num.second >> (64 - shift));
    ulong second = num.second << shift;

    return LongInt(first, second);
}

LongInt operator + (const LongInt& a, const LongInt& b) {
    ulong first = 0, second = 0;
    bool carry = false;

    for (int i = 0; i < 64; i++) {
        bool bita = a.second & (1ull << i);
        bool bitb = b.second & (1ull << i);   
        
        ulong num = bita ^ bitb ^ carry;
        second |= num << i;
        
        carry ^= (bita ^ carry) & (bitb ^ carry);
    }

    for (int i = 0; i < 64; i++) {
        bool bita = a.first & (1ull << i);
        bool bitb = b.first & (1ull << i);   
        
        ulong num = bita ^ bitb ^ carry;
        first |= num << i;

        carry ^= (bita ^ carry) & (bitb ^ carry);
    }

    return LongInt(first, second);
}

LongInt mul10(const LongInt& a) {
    return (a << 3) + (a << 1);
}

bool operator < (const LongInt& a, const LongInt& b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }

    return a.second < b.second;
}

int n, len = 1;
LongInt num[MAXN];
LongInt power[MAXN];

int get(int i, int j) {
    LongInt val(num[i].first ^ num[j].first, num[i].second ^ num[j].second);

    if (val.first == 0 && val.second == 0) {
        return 0;
    }

    if (power[len - 1] < val) {
        return len - 1;
    }

    int pos = upper_bound(power, power + len, val) - power;
    return pos - 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        uint a, b, c, d;
        scanf("%u%u%u%u", &a, &b, &c, &d);

        num[i] = LongInt(a, b, c, d);
    }

    power[0] = LongInt(1ull);

    for (int i = 0; i < 38; i++) {
        LongInt val = mul10(power[len - 1]);
        power[len] = val;
        len++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += 2 * get(i, j);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
