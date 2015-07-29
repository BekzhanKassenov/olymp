#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int str_to_int(string s)
{
	int ans = 0;
	for (int i = s.size() - 1; i >= 0; i--)
		{
			ans *= 10;
			ans += s[i];
		}
	return ans;
}

string int_to_str(int n)
{
	string ans;
	while (n)
		{
			ans += n % 10;
			n /= 10;
		}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	string s = int_to_str(n);
	for (int i = 0; ; i++)
		{
		   string s = int_to_str(n);
         if (s.length() != 4)
         	{
         		 do
         			s = char(0) + s;
         	    while (s.length() < 3);
         	}
        // cout << str_to_int(s) << endl;
         sort(s.begin(), s.end());
         int k = str_to_int(s);
         reverse(s.begin(), s.end());
         k -= str_to_int(s);
         if (k != n)
             n = k;
         else
           {    
             cout << k << endl << i;
             return 0;
           }

		}
}


