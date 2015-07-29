#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string inv(string a)
{
    string c;
    for (int i = a.length() - 1; i >= 0; i--)
        c += a[i];
    return c;    
}

int main()
{
    string a, b;
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    #endif
    char x, y;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    	{
    		cin >> x >> y;
    		a += x;
    		b += y;
    	}
    string c;
    a = inv(a);
    b = inv(b);
    int flag = 0;
    for (int i = 0; i < (max (a.length(), b.length())); i++)
        {
            if (i < a.length())
                flag += a[i] - '0';
            if (i < b.length())
                flag += b[i] - '0';
            c += (flag % 10) + '0';
            flag /= 10;
        }
    if (flag > 0)
        c += flag + '0';
    for (int i = c.length() - 1; i >= 0; i--)
        cout << c[i];
    return 0;
}