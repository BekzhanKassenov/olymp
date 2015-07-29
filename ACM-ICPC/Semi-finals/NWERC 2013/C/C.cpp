#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool used[2000];
double prob[2000];

void dfs(int pos){
    if (prob[pos] == 0.0)
        return;
    for (int i = 2; i <= 11; ++i){
        if (pos - i > 0 && used[pos - i] == 0){
            prob[pos - i] += prob[pos]*(i == 10 ? 4.0 : 1.0)/13.0;
        }
    }
}
int main(){
#ifdef Local
    freopen("in", "r", stdin);
#endif

int n, m;
while (cin >> n >> m) {
    memset(prob, 0, sizeof prob);
    memset(used, 0, sizeof used);
    for (int i = 0; i < n; ++i){
        string ch;
        cin >> ch;
        used[m] = 1;
        prob[m] = 1.0;
        if (ch == "10" || ch == "J" || ch == "Q" || ch == "K")
            m += 10;
        else if (ch == "A")
            m += 11;
        else
            m += ch[0] - '0';
    }
    
    for (int i = 1999; i > 0; --i)
        dfs(i);
    
    double ans = 0.0;
    
    for (int i = 1; i < 11; ++i){
        ans += prob[i];
    }
    printf("%.14lf\n", ans / 10.0);
}
return 0;
}