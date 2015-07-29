#include <fstream>

int a[110], u[110], n, i, s = 1, c;

int g(int n, int m)
{
    return !m ? n : g(m, n % m);
}

main()
{
    std :: ifstream r("input.txt");

    for (r >> n; r >> a[++i];);

    for (; n; s = c ? s / g(s, c) * c : s)
        for (i = n--, c = 0; !u[i]; c++, i = a[i])
            u[i] = 1;

    std :: ofstream ("output.txt") << s;
}
