#include <iostream>
#include <cstdio>
#include <string>
 
using namespace std;
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    string s;
 
    cin >> s;
 
    int n;
 
    cin >> n;
 
    long long tmp = 0;
 
    for (int i = 0; i < (int)s.length(); i++)
        {
            tmp *= 10;
 
            tmp += s[i] - '0';
 
            tmp %= n;
        }
    cout << tmp % n;
    return 0;
}