#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector <int> a;
    a.resize(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    int ans=0;
    int s=-1;
    int mx;
    while (s<n)
        {
            mx=s+1;
            for (int i=s+1;i<n;i++)
                if (a[i]>a[mx]) mx=i;
            if (mx<n) 
            ans+=a[mx]*(mx-s);
            s=mx;
        } 
    cout<<ans;
    return 0;
}
