#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;

ll primes[55] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 
                  83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
                  173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257}; 

ll rev[55][55], x[55];

int pow_mod(ll n, int st, ll mod) {
    ll res = 1;

    while (st) {
        if (st & 1)
            res = (res * n) % mod;

        n = (n * 1ll * n) % mod;
        st >>= 1;
    }

    return res;
}

struct big_int {
    vector <int> arr;

    big_int() {}

    big_int(int n) {
        if (n == 1)
            arr.push_back(1);
        else
            arr.push_back(0);   
    }

    big_int(vector <int>& arr1) : arr(arr1) {}

    void operator += (const big_int& p) {
        int len = arr.size();
        int l = p.arr.size();

        int flag = 0;

        for (int i = 0; i < max(len, l); i++) {
            if (i < len)
                flag += arr[i];

            if (i < l)
                flag += p.arr[i];

            if (i < len)
                arr[i] = flag % 10;
            else    
                arr.push_back(flag % 10);

            flag /= 10; 
        }

        while (flag) {
            arr.push_back(flag % 10);
            flag /= 10;
        }
    }

    big_int operator * (int n) const {
        vector <int> res;

        long long flag = 0;

        for (size_t i = 0; i < arr.size(); i++) {
            flag += arr[i] * n;
            res.push_back(flag % 10);
            flag /= 10;
        }

        while (flag) {
            res.push_back(flag % 10);
            flag /= 10;
        }

        return big_int(res);
    }

    void print() {
        for (int i = arr.size() - 1; i >= 0; i--)
            cout << arr[i];

        cout << endl;   
    }
};

int main() {
    #ifdef Local
        freopen("in", "r", stdin);
    #endif

    int n, k;
    
    cin >> n >> k;

    stringstream ss;

    for (int i = 0; i < n; i++) {
        int t = primes[i];
        ss << t << endl;
        for (int j = 1; j < k; j++)
            primes[i] *= t;
    }

    if (n == 1) {
        cout << primes[0] << endl << primes[0];
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            rev[i][j] = pow_mod(primes[i], primes[j] - 2, primes[j]);
    }

    big_int result(0), mult(1);

    for (int i = 0; i < n; i++) {
        x[i] = -i;

        while (x[i] < 0)
            x[i] += primes[i];

        x[i] %= primes[i];

        for (int j = 0; j < i; j++) {
            ll cur = (x[i] - x[j]) * 1ll * rev[j][i];
            x[i] = (cur % primes[i] + primes[i]) % primes[i];
        }

        result += mult * x[i];
        mult = mult * primes[i];
    }

    if (result.arr.size() >= 500u) {
        cout << "No Solution";
        return 0;
    }

    result.print();

    cout << ss.str();

    return 0;
}                   
