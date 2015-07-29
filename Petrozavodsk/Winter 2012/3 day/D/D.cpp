#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cassert>
#include <queue>

using namespace std;

const int maxn = 100010;

int n, k, next[maxn], val[maxn], color[maxn], number[maxn], max_val[maxn];
vector <int> rev[maxn];
bool start[maxn], used[maxn];

#define MP make_pair

int dfs(int v) {
    color[v] = 1;

    if (color[next[v]] == 0)
        val[v] = 1 + dfs(next[v]);
    else if (color[next[v]] == 1)
        val[v] = 1;
    else
        val[v] = 1 + val[next[v]];  

    color[v] = 2;

    return val[v];
}

void make_comp(int v, int comp_number) {
    number[v] = comp_number;

    if (!number[next[v]])
        make_comp(next[v], comp_number);

    for (size_t i = 0; i < rev[v].size(); i++)
        if (!number[rev[v][i]])
            make_comp(rev[v][i], comp_number);
}

priority_queue <pair <int, int> > q;

int get_end(int v) {
    used[v] = true;
    while (v != next[v] && !used[next[v]]) {
        v = next[v];
        used[v] = true;
    }

    return v;   
}

void calc(int v) {
    val[v] = 1;
    int ma = -1;

    for (int i = 0; i < (int)rev[v].size(); i++) {
        calc(rev[v][i]);
        if (ma == -1 || val[rev[v][i]] > val[rev[v][ma]])
            ma = i;
    }

    for (int i = 0; i < (int)rev[v].size(); i++) {
        if (i != ma) 
            q.push(MP(val[rev[v][i]], rev[v][i]));
        else
            val[v] += val[rev[v][i]];
    }
}

int main() {
    freopen("free.in", "r", stdin);

    int n, k;

    cin >> n >> k;

    memset(start, true, sizeof start);

    for (int i = 0; i < n; i++) {
        cin >> next[i];
        next[i]--;            
        rev[next[i]].push_back(i);
        if (i != next[i])
            start[next[i]] = false;
    }

    int c = 0;

    for (int i = 0; i < n; i++)
        if (!number[i]) {
            make_comp(i, ++c);
            max_val[c] = i;
        }

    for (int i = 0; i < n; i++)
        if (start[i]) 
            dfs(i);

    for (int i = 0; i < n; i++)
        if (color[i] == 0) 
            dfs(i);
    
    for (int i = 0; i < n; i++)
        if (val[max_val[number[i]]] < val[i])
            max_val[number[i]] = i;
    
    for (int i = 1; i <= c; i++) {
        calc(get_end(max_val[i]));
        q.push(MP(val[max_val[i]], max_val[i]));
    }
    
    vector <int> res;
    int ans = 0;

    memset(used, false, sizeof used);

    while (k > 0 && !q.empty()) {
        k--;
        res.push_back(q.top().second);
        used[res.back()] = true;
        ans += q.top().first;
        q.pop();
    }

    for (int i = 0; i < n && k > 0; i++) { 
        if (!used[i]) {
            k--;
            used[i] = true;
            res.push_back(i);
        }
    }

    cout << ans << endl;

    for (size_t i = 0; i < res.size(); i++)
        cout << res[i] + 1 << ' ';


    return 0;
}
