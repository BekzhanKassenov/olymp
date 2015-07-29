#include <cstdio>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int hh, mm, ss;
    
    scanf("%d:%d:%d", &hh, &mm, &ss);
    
    int a[3] = {0, 0, 0};
    
    int x;
    
    while (scanf("%d:", &x) == 1) {
        a[2] = a[1];
        a[1] = a[0];
        a[0] = x;
    }
    
    long long s1 = hh * 60ll * 60ll + mm * 60ll + ss;
    
    long long s2 = a[2] * 60ll * 60ll + a[1] * 60ll + a[0];
    
    s1 += s2;
    
    int days = s1 / (24 * 3600);
    s1 %= (24 * 3600);
    
    hh = s1 / 3600;
    s1 %= 3600;
    
    mm = s1 / 60;
    s1 %= 60;
    
    ss = s1;
    
    printf("%02d:%02d:%02d", hh, mm, ss);
    
    if (days > 0)
        printf("+%d days", days);
        
    return 0;
}