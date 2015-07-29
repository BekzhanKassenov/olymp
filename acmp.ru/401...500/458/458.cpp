#include <iostream>
#include <cstdio>
#include <string>
#include <clocale>

using namespace std;

const int maxn = 210;

int n, m, mod, pos[maxn], ptr;
string s;
char a[maxn][maxn];

int main() {
    setlocale(LC_ALL, "russian_russia");

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> pos[i];

    cin >> s;

    m = (s.size() + n - 1) / n;
    mod = s.size() % n;
    
    if (mod == 0)
        mod = n;

    for (int i = 0; i < n; i++) {
        int index = pos[i] - 1;

        for (int j = 0; j < ((index < mod) ? m : m - 1); j++) {
            a[index][j] = s[ptr++];
            //cerr << index << ' ' << j << ' ' << ptr << endl;
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (a[i][j])
                cout << a[i][j];
        }
    }

    return 0;
}

