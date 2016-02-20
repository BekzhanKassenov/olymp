#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()

int n;
vector <int> a, b;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    b = a;
    sort(all(b));

    int cnt = 0, num = -1;
    int anscnt = 0, ansnum = -1;

    for (int i = 0; i < n; i++) {
        if (b[i] == num) {
            cnt++;
        } else {
            cnt = 1;
            num = b[i];
        }

        if (cnt > anscnt) {
            anscnt = cnt;
            ansnum = num;
        }
    }

    b.clear();

    for (int i = 0; i < n; i++) {
        if (a[i] != ansnum) {
            b.push_back(a[i]);
        }
    }

    for (int i = 0; i < anscnt; i++) {
        b.push_back(ansnum);
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }
    cout << endl;

    return 0;
}
