#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

string int_to_str(int n)
{
    stringstream ss;
    ss << n;
    return ss.str();
}

int str_to_int(string s)
{
    int ans = 0;
    stringstream ss;
    ss << s;
    ss >> ans;
    return ans;
}

void up(string& s)
{
    int i = s.length() - 1;
    while(1)
        {
            if (s[i] == '4')
                {
                    s[i] = '7';
                    break;
                }
            else
                {
                     s[i] = '4';
                     i--;
                }
            if (i == -1)
                {
                    s = '4' + s;
                    break;
                }
        }
}

bool operator < (string& a, string& b)
{
	int lena = a.length();
	int lenb = b.length();
	if (lena < lenb)
		return true;
	if (lena > lenb)
		return false;
	if (lena == lenb)
	   {
	   	for (int i = 0; i < lena; i++)
	   		if (a[i] < b[i])
	   			return true;
	   		else
	   			if (a[i] > b[i])
	   				return false;
	   }
	return false;
}

int next(int n)
{
    string strn = int_to_str(n);
   
    int len = strn.length();
    string ans;
    
    for (int i = 0; i < len; i++)
        ans += '4';

    while (ans < strn)
        up(ans);
    int k = str_to_int(ans);
    return k;
}
 
main()
{
    #ifndef ONLINE_JUDGE
    	freopen("in", "r", stdin);
    #endif

    int l, r;
    cin >> l >> r;
    
    int a1 = l, a2 = next(l);
    long long ans = (abs(min(a2, r) - a1) + 1) * a2;
    a1 = a2;
    
    while (a2 <= r)
        {
            string tmp = int_to_str(a2);
            up(tmp);
            a2 = str_to_int(tmp);
            
            ans += (min(a2, r) - a1) * a2;
            
            //cout << a1 << ' ' << a2 << ' ' << ans << endl;
            
            a1 = a2;
            
            if (a2 == r)
                break;
        }
    
    cout << ans;
}
