#include <fstream>
    
#define W while
#define N 8010
     
char q[N], *p = q + N / 2, *c, *S;
     
main() {
    std::fstream i("input.txt");
    std::ofstream o("output.txt");

    i.get(q, N);
    i.get(p, N, 0);

    W (*p) {
        c = p, S = q; 
 
        W (*S) {
            W (*S > 32) {
                if (*c < 33 | (*c | 32) ^ (*S | 32))
                    goto Q;
                
                S++, c++;
            }
        
            if (*S++ && *c > 32)
                goto Q;
                  
            W (*c < 33)
                c++;
        }
 
        o << '@';
        Q:
        o << *p++;
    }
}