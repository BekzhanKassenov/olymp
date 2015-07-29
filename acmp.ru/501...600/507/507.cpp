#include <iostream>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

ostream& operator << (ostream& out, const vector <bool>& vec) {
    out << '{';
    for (size_t i = 0; i + 1 < vec.size(); i++) {
        out << vec[i] << ", ";
    }

    out << vec.back() << '}';
    return out;
}

int g[5][5];
int a[50];
int n, x;
vector <int> initial;
set <vector <bool> > was;
set <vector <int> > result;

void go(const vector <bool>& vec) {
    if (was.count(vec)) {
        return;
    }

    was.insert(vec);

    bool changed = false;

    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = 0; j < vec.size(); j++) {
            if (vec[j] || vec[i] || i == j) {
                continue;
            }

            vector <bool> temp(vec);

            if (g[initial[i]][initial[j]]) {
                temp[j] = true;
                changed = true;
                go(temp);
            }
        }
    }

    if (!changed) {
        vector <int> cnt(n);

        for (size_t i = 0; i < vec.size(); i++) {
            if (!vec[i]) {
                cnt[initial[i]]++;
            }
        }

        result.insert(cnt);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        while (x--) {
            initial.push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    vector <bool> vec(initial.size());

    go(vec);

    printf("%u\n", result.size());

    for (set <vector <int> >::iterator it = result.begin(); it != result.end(); it++) {
        for (size_t i = 0; i < it->size(); i++) {
            printf("%d ", (*it)[i]);
        }

        puts("");
    }

    return 0;
}
