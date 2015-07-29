#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct BigInt {
    vector <int> nmb;
    
    BigInt() { 
        nmb.push_back(0);
    }
    
    void operator += (const BigInt& b) {
        int len = nmb.size();
        int lenb = b.nmb.size();
        
        int flag = 0;
        
        for (int i = 0; i < min(len, lenb); i++) {
            flag += nmb[i] + b.nmb[i];
            nmb[i] = flag % 10;
            flag /= 10;
        }
        
        for (int i = min(len, lenb); i < max(len, lenb); i++) {
            if (len < lenb) {
                flag += b.nmb[i];
                nmb.push_back(flag % 10);
            } else {
                flag += nmb[i];
                nmb[i] = flag % 10;
            }
            
            flag /= 10;
        }
        
        while (flag) {
            nmb.push_back(flag % 10);
            flag /= 10;
        }
    }
};

ostream& operator << (ostream& c, const BigInt& b) {
    for (int i = b.nmb.size() - 1; i >= 0; i--)
        c << b.nmb[i];
        
    return c;
}

BigInt ONE;

BigInt mem[30][30][30];
bool calced[30][30][30];

BigInt go(int n, int a, int b) {
    if (n == 0)
        return ONE;
        
    if (calced[n][a][b])
        return mem[n][a][b];
        
    calced[n][a][b] = true;
        
    for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++)
            mem[n][a][b] += go(n - 1, a - i, b - j);
            
    return mem[n][a][b];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    ONE.nmb[0] = 1;
    
    int n, a, b;
    cin >> n >> a >> b;
    
    cout << go(n, a, b) << endl;
    
    return 0;
}
