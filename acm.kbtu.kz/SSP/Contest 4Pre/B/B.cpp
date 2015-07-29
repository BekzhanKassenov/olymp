#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    stack <int> q;
    bool ok = true;
    for (int i=0;i<s.length();i++)
        {
            if (s[i]=='(')
                q.push(1);
            
            if (s[i]=='{')
                q.push(2);
            
            if (s[i]=='[')
                q.push(3);
            
            if (s[i]=='<')
                q.push(4);
            
            if ((s[i]==')'))
                {
                    if (q.top()==1)
                        {
                            q.pop();
                            continue;
                        }
                    else
                    ok = false;
                }
           if ((s[i]=='}'))
                {
                    if (q.top()==2)
                        {
                            q.pop();
                            continue;
                        }
                    else
                        ok = false;
                }
            if ((s[i]==']'))
                {
                    if (q.top()==3)
                        {
                            q.pop();
                            continue;
                        }
                    else
                        ok = false;
                }
            if ((s[i]=='>'))
                {
                    if (q.top()==4)
                        {
                            q.pop();
                            continue;
                        }
                    else
                        ok = false;
                }
        }
    if (!q.empty() || !ok)
        cout << "NO";
    if (q.empty() && ok)
        cout << "YES";
   return 0;
}              
