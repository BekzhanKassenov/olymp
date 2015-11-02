#include <iostream>
     
#define W while
#define N 8010
#define A std::
      
char q[N], *p = q + N / 2, *c, *S;
      
main() {
    A cin.get(q, N);
    A cin.get(p, N, 0);
 
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
  
        A cout << '@';
        Q:
        A cout << *p++;
    }
}