#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{   
    queue <int> q;
    int m;
    cin >> m;
    for (int i=0;i<m;i++)
        {
            char c;
            cin >> c;
            int k;
            if (c=='+')
                {
                    cin >> k;
                    q.push(k);
                }
            else
                {
                    cout << q.front() << endl;
                    q.pop();    
                }   
        }
     return 0;
}
