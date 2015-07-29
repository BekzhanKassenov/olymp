
#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
    {
        if (a==b) return a;
        if (a<b) return gcd(b-a,a);
        if (a>b) return gcd(a-b,b);
    }

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for (int i=1;i<n;i++)
        {
            if (gcd(n,i)==1) ans++;
        }
    cout<<ans;
    return 0;
}
