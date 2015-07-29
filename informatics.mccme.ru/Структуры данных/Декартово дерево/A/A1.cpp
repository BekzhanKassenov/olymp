#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 50050;

typedef struct Node* pNode;

struct Node {
    int x, y;
    int num;
    pNode l, r;
    
    Node() : l(NULL), r(NULL) { }
    
    Node(int x, int y, int num) : x(x), y(y), num(num), l(NULL), r(NULL) { }
};

struct triple {
    int x, y, num;
    
    void read() {
        scanf("%d%d", &x, &y);
    }
    
    bool operator < (const triple& t) const {
        return x < t.x;
    }
};

int n, x, y, par[maxn], Left[maxn], Right[maxn];
vector <pNode> stck;
pNode root;
triple arr[maxn];

void add(pNode to_add) {
    while (!stck.empty()) {
        if (stck.back() -> y > to_add -> y)
            stck.pop_back();
        else
            break;
    }
    
    if (stck.empty()) {
        to_add -> l = root;
        
        if (root) {
            par[root -> num] = to_add -> num;
            Left[to_add -> num] = root -> num;
        }
        
        root = to_add;
    } else {
        pNode parent = stck.back();
        to_add -> l = parent -> r;
        parent -> r = to_add;
        
        Right[parent -> num] = to_add -> num;
        par[to_add -> num] = parent -> num;
        
        if (to_add -> l) {
            Left[to_add -> num] = to_add -> l -> num;
            par[to_add -> l -> num] = to_add -> num;    
        }
    }
    
    stck.push_back(to_add);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        arr[i].read();
        arr[i].num = i + 1;
    }
    
    sort(arr, arr + n);
    
    for (int i = 0; i < n; i++) {
        add(new Node(arr[i].x, arr[i].y, arr[i].num));
    }
    
    puts("YES");
    
    for (int i = 1; i <= n; i++)
        printf("%d %d %d\n", par[i], Left[i], Right[i]);
    
    return 0;
}
