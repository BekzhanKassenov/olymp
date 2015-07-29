#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cstring>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

int p;
int n;
vector < int > g[10050];

void addEdge(int from, int to) {
    g[from].push_back(to);
    g[to].push_back(from);
}

int main() {
    //assert(freopen("in", "r", stdin));
    //assert(freopen("output.txt", "w", stdout));

    scanf("%d", &p);

    n++;
    for (int i = 1; i <= p + 1; i++) {
        n++;
        addEdge(1, n);    
    }

    for (int i = 2; i <= p + 2; i++) {
        for (int j = 1; j <= p; j++) {
            n++;
            addEdge(i, n);
        }
    }

    for (int i = 0; i < p; i++) 
        for (int j = 0; j < p; j++) {
            n++;
            int a, b;
            for (int k = 0; k < p + 1; k++) {
                if (k < p) {
                    a = k; b = (i * k + j) % p;
                }
                else {
                    a = p; b = i;
                }
                addEdge(n, p + 3 + (a * p) + b);
            }
        }

    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        sort(ALL(g[i]));
        for (int j = 0; j < (int) g[i].size(); j++)
            printf("%d ", g[i][j]);
        printf("\n");    
    }

    return 0;
}
