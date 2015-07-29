#include <fstream>

int g[110][110], n, s, f, i, j, k, I = 1e9;

main() {
    std :: ifstream q("input.txt"); 
    
    for (q >> n >> s >> f; i < n; i++)
        for (j = 0; j < n && q >> g[i][j]; j++)
            g[i][j] += (g[i][j] < 0) * I;
                    
    for (; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                g[i][j] = std :: min(g[i][j], g[i][k] + g[k][j]);

    std :: ofstream ("output.txt") << (g[--s][--f] - I + 1 ? g[s][f] : -1);
}