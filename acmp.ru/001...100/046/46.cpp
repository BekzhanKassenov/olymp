#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    if (n==0) 
        {
            cout<<3;
            return 0;
        }
    string e="2.7182818284590452353602875";
    if (n==25) 
        {
            cout<<e;
            return 0;
        }
    e=e.substr(0,n+3);
    if (e[e.length()-1]-'0'>=5) e[e.length()-2]++;
    e=e.substr(0,n+2);
    cout<<e;
    return 0;
}
