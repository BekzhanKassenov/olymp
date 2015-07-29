#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string a,b;
    
    int z[27];
    
    for (int i=0;i<27;i++)
        z[i]=0;
    
    cin>>a>>b;
    
    for (int i=0;i<a.length();i++)
        z[int(a[i]-'A')]++;
    
    for (int i=0;i<b.length();i++)
        z[int(b[i]-'A')]--;
    
    for (int i=0;i<27;i++)
        if (z[i]!=0) 
            {
                cout<<"NO";
                return 0;
            }
    cout<<"YES";    
    return 0;
}
