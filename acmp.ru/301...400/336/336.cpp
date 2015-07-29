#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    int k=1, mx=1,mn=1;
    for (int i=0;i<s.length();i++)
        {
            if (s[i]=='1') k++;
            if (s[i]=='2') k--;
            mx=max(mx,k);
            mn=min(mn,k);
        }
    cout<<mx-mn+1;
    return 0;
}
