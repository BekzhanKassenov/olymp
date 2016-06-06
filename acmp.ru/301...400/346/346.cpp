#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()

string int_to_str(long long a) {
    string ans;
    while (a) {
        ans += a % 10;
        a /= 10;
    }

    return ans;
}

long long str_to_int (const string& s) {
    long long ans = 0;
    for (size_t i = 0; i < s.length(); i++) {
        ans *= 10;
        ans += s[i];
    }
    
    return ans;
}

int remove_zeroes(string& s) {
    int cnt = 0;
    reverse(all(s));

    while (!s.empty() && s.back() == 0) {
        cnt++;
        s.pop_back();
    }   

    reverse(all(s));
    return cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b, c;
    cin >> a >> b >> c;
    
    string stra = int_to_str(a);
    string strb = int_to_str(b);
    
    sort(stra.begin(), stra.end());
    sort(strb.begin(), strb.end());

    int cnt0b = remove_zeroes(strb);

    long long ans = -1;
    long long ansv = -1;
    do {
        long long k = str_to_int(stra);
        long long v = c - k;

        string str = int_to_str(v);
        sort(str.begin(), str.end());
        
        int cnt1 = remove_zeroes(str);
        if (cnt1 <= cnt0b && str == strb && (ans == -1 || ans > k)) {
            ans = k;
            ansv = v;
        }

    } while (next_permutation(stra.begin(), stra.end()));
    
    if (ans == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << ans << ' ' << ansv << endl;
    }

    return 0;
}
