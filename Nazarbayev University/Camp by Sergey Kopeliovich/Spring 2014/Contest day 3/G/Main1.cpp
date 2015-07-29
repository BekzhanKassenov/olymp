/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define File "polyomino"

int h, w, tot, cursz, curcomp;
char c[11][11];
bool used[11][11];
int ans[11][11];
int dx[] = {0, 1, 0};
int dy[] = {-1, 0, 1}; 
double begin;

vector<int> mask;

inline void print();

inline bool find_(int& x, int& y){
    x = -1, y = -1;
    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j){
            if (ans[i][j] == 0 && c[i][j] == 'X') {
                x = i, y = j;
                return true;
            }
        }
    }
    
    return false;
}

inline bool ok(int x, int y){
    return (x >= 0 && x < h && y >= 0 && y < w);
}

inline bool fill_(int x, int y){
    ans[x][y] = curcomp;
    cursz++;
    for (size_t i = 0; i < mask.size(); ++i, cursz++) {
        x += dx[mask[i]];
        y += dy[mask[i]];
        if (!ok(x, y) || ans[x][y] != 0 || c[x][y] == '.')
            return 0;
        ans[x][y] = curcomp;
    }
    return 1;
}  

bool found = false;

void dfs(int x, int y, int k, int cur){
    used[x][y] = 1;
    if (cur == 0) {
        curcomp = 1;
        
        for (int i = 0; i < 11; ++i)
            memset(ans[i], 0, sizeof(int)*10);
            
        for (int i = 0; i < k; ++i){
            int fx, fy;
            if (!find_(fx, fy)) {
                used[x][y] = 0;
                return;
            }
            if (!fill_(fx, fy)){
                used[x][y] = 0;            
                return;
            }
            curcomp++;           
        }

        found = true;
        return; 
    }
    else {
        for (int i = 0; i < 3; ++i){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (ok(tx, ty) && !used[tx][ty] && c[tx][ty] == 'X'){
                mask.push_back(i);
                dfs(tx, ty, k, cur-1);
                if (found)
                    return;
                mask.pop_back();
            }
      
        }    
    }
    if ((clock() - begin) / CLOCKS_PER_SEC > 1.8)
        return;
        
    used[x][y] = 0;
}

void tri(int k){
    int x, y;
    find_(x, y);
    dfs(x, y, k, tot / k - 1);
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
    
    begin = clock();
    
    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j){
            cin >> c[i][j];
            if (c[i][j] == 'X')
                tot++;
        }
    }
    for (int k = 2; k <= 5; ++k){
        if (tot % k != 0)
            continue;
        tri(k);
        
        if (found) {
            print();
            return 0;
        }
    }
    
    cout << "No solution";
    
    double end = clock();
    
    cerr << (end - begin) / CLOCKS_PER_SEC;
    
    return 0;
}
