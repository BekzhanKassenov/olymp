#include <fstream>
      
int g[10010][110], x, y, c, n;
  
main() {
    std::fstream q("input.txt");
    std::ofstream w("output.txt");
   
    for (q >> n >> n; n--; g[g[y][c] = x][c] = y)
        q >> x >> y >> c;
   
    for (y = 1, q >> n; q >> x; ) 
        if (!(y = g[y][x]) && w << "INCORRECT")
            goto Q;
   
    w << y;
Q:    
    w.close();
}