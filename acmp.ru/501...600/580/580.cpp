#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    double a,b,c;
    cin>>a>>b>>c;
    double z;
    cin>>z;
    double p=(a+b+c)/2;
    double s=sqrt(p*(p-a)*(p-b)*(p-c));
    double r=s/p;
    if (z<=r)
        cout<<"YES";
    else cout<<"NO";
    return 0;
}
