/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "list"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 500010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

typedef struct Node* pNode;

struct Node {
    int val;
    pNode prev, next;
    
    Node() : val(0), prev(NULL), next(NULL) { }
    
    Node(int val) : val(val), prev(NULL), next(NULL) { }
};

pNode begin, end, arr[maxn];
int n, m, x, y, a[maxn], last;
char c;

void push_back(int val) {
    arr[val] = new Node(val);
    arr[val] -> prev = end;
    
    if (begin == NULL) {
        begin = arr[val];
    } else {
        end -> next = arr[val];
    }
    
    end = arr[val];
}

void move_before(pNode a, pNode b) {
    a -> prev -> next = a -> next;
    a -> next -> prev = a -> prev;
    
    a -> next = b;
    a -> prev = b -> prev;
    
    b -> prev -> next = a;
    b -> prev = a;
}

void move_after(pNode a, pNode b) {
    a -> prev -> next = a -> next;
    a -> next -> prev = a -> prev;
 
    a -> next = b -> next;
    a -> prev = b;
    
    b -> next -> prev = a;
    b -> next = a;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i <= n + 1; i++)
        push_back(i);

    for (int i = 0; i < m; i++) {
        scanf("\n%c%d%d", &c, &x, &y);
        
        if (c == 'A')
            move_before(arr[x], arr[y]);
        else
            move_after(arr[x], arr[y]);
    }
    
    stringstream ss;
    
    pNode cur = begin -> next;
    
    return 0;
}
