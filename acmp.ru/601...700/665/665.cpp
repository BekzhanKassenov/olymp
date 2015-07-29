#include <iostream>
#include <cstdio>

using namespace std;

struct Time {
    int h, m;
    
    void read() {
        scanf("%d:%d", &h, &m);
    }

    void print() const {
        printf("%02d:%02d", h, m);
    }

    void operator ++ (int) {
        m++;
        
        h += m / 60;
        m %= 60;

        h %= 24;
    }

    bool is_pal() const {
        int a = h % 10;
        int b = h / 10;

        int bb = m % 10;
        int aa = m / 10;
        
        return a == aa && b == bb;
    }
};

Time t;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    t.read();

    do {    
        t++;
    } while (!t.is_pal());

    t.print();

    return 0;
}
