#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

#define all(x) (x).begin(), (x).end()

int come[110], take[110];
int size[110], cell[110];
int _time[1010];
int cap[15];
int n, m;
vector <int> items[15];

void add(int inum, int cnum) {
    items[cnum].push_back(inum);
    cap[cnum] -= size[inum];
    cell[inum] = cnum;
}

void remove(int inum) {
    int cnum = cell[inum];

    vector <int>::iterator it = find(all(items[cnum]), inum);

    assert(it != items[cnum].end());
    items[cnum].erase(it);
    cap[cnum] += size[inum];
}

int find_best(int size) {
    int pos = -1;

    for (int i = 1; i <= n; i++) {
        if (cap[i] >= size && (pos == -1 || cap[i] < cap[pos])) {
            pos = i;
        }
    }

    return pos;
}

bool cmp(int a, int b) {
    if (size[a] != size[b]) {
        return size[a] < size[b];
    }

    if (cap[cell[a]] + size[a] != cap[cell[b]] + size[b]) {
        return cap[cell[a]] + size[a] < cap[cell[b]] + size[b];
    }

    return a < b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &cap[i]);
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &size[i], &come[i], &take[i]);
        
        _time[come[i]] = i;
        _time[take[i]] = i;
    }

    for (int cur = 0; cur < 1010; cur++) {
        if (_time[cur] == 0) {
            continue;
        }

        int inum = _time[cur];

        if (come[inum] == cur) {
            int pos = find_best(size[inum]);    

            if (pos != -1) {
                add(inum, pos);
                printf("put cargo %d to cell %d\n", inum, pos);
            } else {
                int mnum = -1, to = -1;

                for (int i = 1; i <= n; i++) {
                    for (size_t j = 0; j < items[i].size(); j++) {
                        int tnum = items[i][j];

                        if (cap[i] + size[tnum] < size[inum]) {
                            continue;
                        }

                        int temp = cap[i];
                        cap[i] = 0;
                        int pos = find_best(size[tnum]);
                        cap[i] = temp;

                        if (pos == -1) {
                            continue;
                        }

                        if (mnum == -1 || cmp(tnum, mnum)) {
                            mnum = tnum;
                            to = pos;
                        }
                    }
                }

                if (mnum != -1) {
                    int cnum = cell[mnum];
                    
                    printf("move cargo %d from cell %d to cell %d\n", mnum, cnum, to);
                    remove(mnum);
                    add(mnum, to);

                    printf("put cargo %d to cell %d\n", inum, cnum);
                    add(inum, cnum);
                } else {
                    printf("cargo %d cannot be stored\n", inum);
                }
            }

        } else {
            if (cell[inum] != 0) {
                printf("take cargo %d from cell %d\n", inum, cell[inum]);
                remove(inum);
            }
        }
    }

    return 0;
}
