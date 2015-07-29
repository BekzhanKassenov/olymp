#include <iostream>

using namespace std;
int n,m;
int f(int z)
{
    if (z==1) return 1;
    else return (1+(f(z-1)+m-1) % z);
}

main()
{
    cin >> n >> m;
    cout << f(n);
}