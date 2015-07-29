#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool kuhn(int v) {
    if (used[v])
        return false;

    used[v] = true;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (mt[to] == -1 || kuhn(mt[to])) {
            mt[to] = v;
            return true;    
        }
    }

    return false;
}