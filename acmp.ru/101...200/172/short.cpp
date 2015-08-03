#include <fstream>

__int64 t, n;
char s[110], *q = s;

main() {
    std :: fstream i("input.txt");

    for (i >> s >> n; *q; )
        t = (t * 10 + *q++ - 48) % n;
        
    std :: ofstream ("output.txt") << t;
}
