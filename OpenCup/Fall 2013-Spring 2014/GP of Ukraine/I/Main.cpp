/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <cstdio>
#include <cstring>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

const int maxn = 1000010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int g1[maxn], g2[maxn];
int n;

struct Stack {
    int first[maxn / 2], second[maxn / 2];
    int last;
    
    Stack() { 
        last = 0;
        memset(first, 0, sizeof first);
        memset(second, 0, sizeof second);
    }
    
    void push(int a, int b) {
        first[last] = a;
        second[last] = b;
        last++;
        
        //printf("Last %d\n", last);
    }
    
    void pop() {
        last--;
    }
    
    bool empty() {
        return (last <= 0);
    }
};

Stack st;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &g1[i], &g2[i]);
    }
    
    st.push(1, 0);
    
    puts("DFS");
    
    while (!st.empty()) {
        int a = st.first[st.last - 1];
        int& b = st.second[st.last - 1];
        
        //printf("%d %d\n", a, b);
        
        if (b == 0) {
            printf("%d\n", a);
            
            if (g1[a] == 0) {
                st.pop();
                continue;
            }
            b++;
            st.push(g1[a], 0);
        } else if (b == 1) {
            b++;
            st.push(g2[a], 0);
        } else {
            st.pop();
        }
    }
        
    return 0;
}
