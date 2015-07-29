#include <iostream>
#include <cstdio>
#include <string>
#define abs (x) (x < 0) ? (-x) : x

using namespace std;

int i;

string s;

bool ok = true;

bool next_Int()
{
   string ans;
   while (s[i] >= '0' && s[i] <= '9' && i < s.length())
      {
         ans += s[i];
         i++;
      }
   if (s[i] == '0' || ans == "1" || ans[0] == '0')
      return false;
   return true;
}

string next_vv()
{
   string ans;
   if (s[i] >= '0' && s[i] <= '9')
      ok = next_Int();
   if (i < s.length())
   	ans += s[i];
   i++;
   if (s[i] <= 'z' && s[i] >= 'a')
      {
         ans += s[i];
         i++;
      }
   return ans;
}

int main()
{
   
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   cin >> s;
   string a,b;
   while (i < (int)s.length())
      {
          a = b;
          b = next_vv();
          if (!ok || a == b)
             {
                cout << "NO";
                return 0;
             }  
      } 
   cout << "YES";
   return 0;
} 
