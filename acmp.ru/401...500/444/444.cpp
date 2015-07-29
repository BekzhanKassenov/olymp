#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string int_to_str(int n) {
    if (n == 0)
        return "0";
    
    string res;

    if (n < 0)
        res = "-";
    
    while (n) {
        res += abs(n) % 10 + '0';
        n /= 10;
    }
    
    reverse(res.begin() + (res[0] == '-'), res.end());
    
    return res;
}

int n, a[1010];

string get_min(int l, int r) {
    string temp1, temp2 = int_to_str(a[l]) + ", ..., " + int_to_str(a[r]);

    if (r - l + 1 >= 4)
        return temp2;

    for (int j = l; j <= r; j++) {
        temp1 += int_to_str(a[j]);

        if (j < r)
            temp1 += ", ";
    }

    if (temp1.size() <= temp2.size())
        return temp1;

    return temp2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
     
    cin >> n;
     
    for (int i = 0; i < n; i++)
        cin >> a[i];
         
    sort(a, a + n);
    n = unique(a, a + n) - a;

    vector <string> res;
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1) {
            r++;
        } else {
            res.push_back(get_min(l, r));
            l = r = i;
        }
    }

    res.push_back(get_min(l, r));
     
    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i];

        if (i + 1 < res.size())
            cout << ", ";
    }

    cout << endl;
    
    return 0;
}
