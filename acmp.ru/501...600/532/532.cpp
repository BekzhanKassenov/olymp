#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()

const int MAXN = 100010;

int n, m, p;
multiset <pair <int, int> > Set1, Set2;
long long sumGood1, sumGood2;
long long sumBad1, sumBad2;
vector <pair <int, int> > addVec[100010], removeVec[100010];

void addSet(const pair <int, int>& val, multiset <pair <int, int> >& Set, long long& sumGood, long long& sumBad) {
    sumGood += val.second + val.first;
    sumBad += val.second;
    Set.insert(val);
}

void removeSet(const pair <int, int>& val, multiset <pair <int, int> >& Set, long long& sumGood, long long& sumBad) {
    sumGood -= val.second + val.first;
    sumBad -= val.second;
    Set.erase(Set.find(val));
}

void normalize() {
    while ((int)Set1.size() > m) {
        auto p = *Set1.begin();
        removeSet(p, Set1, sumGood1, sumBad1);
        addSet(p, Set2, sumGood2, sumBad2);
    }

    while ((int)Set1.size() < m && !Set2.empty()) {
        auto p = *(--Set2.end());
        removeSet(p, Set2, sumGood2, sumBad2);
        addSet(p, Set1, sumGood1, sumBad1);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &p);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);

        if (a < b) {
            ans += 1ll * (d - c) * b;
        } else {
            addVec[c + 1].emplace_back(a - b, b);
            removeVec[d].emplace_back(a - b, b);
        }
    }

    for (int i = 0; i <= p; i++) {
        for (const auto& it: addVec[i]) {
            addSet(it, Set1, sumGood1, sumBad1);
        }

        normalize();

        ans += sumGood1 + sumBad2;

        for (const auto& it: removeVec[i]) {
            if (Set1.find(it) != Set1.end()) {
                removeSet(it, Set1, sumGood1, sumBad1);
            } else {
                assert(Set2.find(it) != Set2.end());
                removeSet(it, Set2, sumGood2, sumBad2);
            }
        }

        normalize();
    }

    printf("%lld\n", ans);

    return 0;
}
