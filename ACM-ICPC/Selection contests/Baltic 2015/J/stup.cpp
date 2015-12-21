/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char type;
int last;

deque <int> vec;

void add(char type) {
    if (type == 'F') {
        vec.push_front(last);
    } else {
        vec.push_back(last);
    }

    last++;
}

int query(int x) {
    int pos = find(all(vec), x) - vec.begin();

    int rest = vec.size() - pos - 1;

    if (rest < pos) {
        for (int i = 0; i < rest; i++) {
            vec.push_front(vec.back());
            vec.pop_back();
        }
        vec.pop_back();
    } else {
        for (int i = 0; i < pos; i++) {
            vec.push_back(vec.front());
            vec.pop_front();
        }

        vec.pop_front();
    }

    return min(rest, pos);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("\n%c", &type);

        if (type == 'O') {
            int x;
            scanf("%d", &x);
            printf("%d\n", query(x - 1));    
        } else {
            add(type);
        }   
    }
    
    return 0;
}
