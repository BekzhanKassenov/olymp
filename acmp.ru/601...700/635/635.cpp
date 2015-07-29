#include <iostream>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
struct Team {
    int id, problems, penalty;
 
    void read() {
        scanf("%d%d%d", &id, &problems, &penalty);
    }
 
    bool operator < (const Team& rhs) const {
        if (problems != rhs.problems)
            return problems > rhs.problems;
 
        return penalty < rhs.penalty;
    }
};
 
int last, ans[2010], n, m;
Team low[1010], temp;
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    scanf("%d%d", &n, &m);
 
    for (int i = 1; i <= n; i++) {
        temp.read();
 
        if (temp.problems)
            low[++last] = temp;
    }
 
    n = last;
    last = 0;
 
    sort(low + 1, low + n + 1);
 
    int mid = n / 2;
 
    for (int i = 1; i <= n; i++) {
        if (low[i].problems == low[1].problems || 
            low[i].problems > low[mid].problems)
            ans[last++] = low[i].id;
    }
 
    for (int i = 0; i < m; i++) {
        temp.read();
 
        if (temp.problems)
            ans[last++] = temp.id;
    }
 
    sort(ans, ans + last);
 
    printf("%d\n", last);
 
    for (int i = 0; i < last; i++)
        printf("%d ", ans[i]);
 
    return 0;
}