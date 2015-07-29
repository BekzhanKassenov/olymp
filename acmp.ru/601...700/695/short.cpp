#include <fstream>

using namespace std;

#define A(x) max(x, -x)

char a, b, c, d, g, h;

int e[] = {1,  1, -1, -1, 2,  2, -2, -2}, f[] = {2, -2,  2, -2, 1, -1,  1, -1}, i, j = 9;

int F(int q, int w) {
    if (q == c && w == d)
        return 0;

    return 2 - (A(q - c) == A(w - d));
}

main() {
    ifstream q("input.txt");
    ofstream w("output.txt");

    q >> a >> b >> c >> d;

    a -= 65;
    b -= 49;

    c -= 65;
    d -= 49;
    
    if ((c + d) % 2)
        w << -1;
    else if (a == c && b == d)
        w << 0;
    else if ((a + b) % 2) {

        for (; i < 8; ) {
            g = a + e[i];
            h = b + f[i++];

            if (g >= 0 && g < 9 && h >= 0 && h < 9)
                j = min(j, F(g, h) + 1);
        }
        
        w << j;

    } else 
        w << F(a, b);
}
