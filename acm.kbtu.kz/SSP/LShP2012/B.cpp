#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a==0 || b==0)
        return a+b;
    if (a>b)
        return gcd(a%b,b);
    return gcd(b%a,a);
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b);
    return 0;
}
