/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define File "polyomino"

int h, w, tot, cursz, curcomp, last;
char c[11][11];
bool used[11][11];
int ans[11][11];
pair<int, int> comps[6];
int dx[] = {0, 1, 0};
int dy[] = {-1, 0, 1}; 
vector<int> mask;
void print();
pair<int, int> find_(int ver){
    if (comps[ver] != make_pair(-1, -1))
        return comps[ver];
    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j){
            if (ans[i][j] == 0 && c[i][j] == 'X')
                return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}
bool ok(pair<int, int> ver){
    if (ver.F < 0 || ver.S < 0 || ver.F >= h || ver.S >= w)
        return 0;
    return 1;
}
bool fill_(pair<int, int> ver){
    ans[ver.F][ver.S] = curcomp;
    cursz++;
    for (size_t i = last; i < mask.size(); ++i, cursz++) {
        ver.F += dx[mask[i]];
        ver.S += dy[mask[i]];
        if (!ok(ver) || ans[ver.F][ver.S] != 0 || c[ver.F][ver.S] == '.')
            return 0;
        ans[ver.F][ver.S] = curcomp;
    }
    comps[curcomp] = ver;
    return 1;
}  
void dfs(pair<int, int> ver, int k, int cur){
    used[ver.F][ver.S] = 1;
    if (cur == 0 || (tot - cur)%10 == 0){
        for (int j = 1; j <= k; ++j){
            pair<int, int> tp;
            curcomp = j;
            tp = find_(j);
            if (!fill_(tp)){
                used[ver.F][ver.S] = 0;
                last = 0;
                for (int i = 0; i < 6; ++i)
                    comps[i] = make_pair(-1, -1);          
                for (int i = 0; i < 11; ++i)
                     memset(ans[i], 0, sizeof(int)*10);
                return;
            }
        }
            last += mask.size();
            if (cur == 0){
             print();
             exit(0);
            }
    }
    else {
        for (int i = 0; i < 3; ++i){
            pair<int, int> to = ver;
            to.F += dx[i];
            to.S += dy[i];
            if (ok(to) && !used[to.F][to.S]){
                mask.push_back(i);
                dfs(to, k, cur-1);
                mask.pop_back();
            }
      
        }    
    }
    used[ver.F][ver.S] = 0;
}
void tri(int k){
    pair<int, int> tp;
    tp = find_(1);
    dfs(tp, k, tot/k-1);
}
void print() {
    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j)
            cout << ans[i][j];
        cout << endl;
    }
}
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    cin >> h >> w;
    double begin = clock();
    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j){
            cin >> c[i][j];
            if (c[i][j] == 'X')
                tot++;
        }
    }
    for (int k = 2; k <= 5; ++k){
        if (tot%k != 0)
            continue;
        tri(k);
    }
    cout << "No solution";
    double end = clock();
    cerr << (end - begin)/CLOCKS_PER_SEC;
    return 0;
}
