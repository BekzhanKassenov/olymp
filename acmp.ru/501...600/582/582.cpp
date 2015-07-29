#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

vector <int> perm1;
vector <int> perm2;
set <vector <int> > used;
vector <int> first, second;

vector <int> apply_perm(vector <int>& vec, const vector <int>& perm) {
    vector <int> result(6);

    for (int i = 0; i < 6; i++) {
        result[i] = vec[perm[i]];
    }

    return result;
}

bool go(vector <int> vec) {
    if (vec == second) {
        return true;
    }

    if (used.count(vec)) {
        return false;
    }

    used.insert(vec);

    for (int i = 0; i < 4; i++) {
        vec = apply_perm(vec, perm1);

        if (go(vec)) {
            return true;
        }
    }

    for (int i = 0; i < 4; i++) {
        vec = apply_perm(vec, perm2);

        if (go(vec)) {
            return true;
        }
    }

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    first.resize(6);
    second.resize(6);
    perm1.push_back(2); 
    perm1.push_back(3);
    perm1.push_back(1);
    perm1.push_back(0);
    perm1.push_back(4);
    perm1.push_back(5);

    perm2.push_back(5);
    perm2.push_back(4);
    perm2.push_back(2);
    perm2.push_back(3);
    perm2.push_back(0);
    perm2.push_back(1);

    for (int i = 0; i < 6; i++) {
        scanf("%d", &first[i]);
    }

    for (int i = 0; i < 6; i++) {
        scanf("%d", &second[i]);
    }

    if (go(first)) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}
