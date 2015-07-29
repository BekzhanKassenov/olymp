#include <iostream>
#include <cstdio>

using namespace std;

int a[10];

void clc(int m)
{
    int c=m;
    while (c>0)
        {    
            a[c%10]++;
            c/=10;
        }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            clc(i*j);
    for (int i=0;i<10;i++)    
        cout<<a[i]<<endl;
    return 0;
}
