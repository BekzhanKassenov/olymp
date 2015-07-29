#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1010;

vector <pair <int, int> > a, b;
pair <int, int> x;
int n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x.first, &x.second);

        if (x.second < 0)
            b.push_back(x);
        else
            a.push_back(x);
    }

    sort(a.begin(), a.end());

    int sum = 0;

    for (size_t i = 0; i < a.size(); i++) {
        if (a[i].first <= sum)
            sum += a[i].second;
    }

    sort(b.begin(), b.end());



    return 0;
}
