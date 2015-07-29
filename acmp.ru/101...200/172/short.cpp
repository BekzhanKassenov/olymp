#include <fstream>
#include <string>

__int64 t, n, q;

main()
{
    std :: fstream i("input.txt"); 
    
    std :: string s;

    for (i >> s >> n; q < s.size(); q++)
        t = (t * 10 + s[q] - 48) % n;

    std :: ofstream ("output.txt") << t;
}
