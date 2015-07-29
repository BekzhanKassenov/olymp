/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

string code;

char c[52];

int n;
string s, res;
string ans;
int lst;

void ask(string s) {
#ifndef Local
    cout << "? " << s << endl;
    cin >> res;
#else
    int a = 0, b = 0;                         
    for (int i = 0; i < (int) code.length(); i++)
        if (s[i] < code[i])                      
            a++;                              
        else                                  
            b++;                              
                                              
    if (a > b)                                
        res = "<";                  
    else                                      
        res = ">=";                 
#endif
}

void found(string s) {
#ifdef Local
    assert(s == code);
#endif    
    cout << "! " << s << endl;
    exit(0);
}

int main() {
    for (int i = 0; i < 26; i++)
        c[i] = (char) ('A' + i);
    for (int i = 0; i < 26; i++)
        c[26 + i] = (char) ('a' + i);

#ifdef Local
    cin >> code;
#endif
    
    cin >> n;
    s.append(n, 'A');
    
    ask(s);
    if (res == ">=") {
        if (n == 1) 
            found("A");
        puts("Impossible");
        return 0;    
    }

    for (int i = 0; i < n; i++) {
        s[i] = 'z';
        ask(s);
        if (res == ">=") {
            lst = i;
            break;
        }
    }

    ans = s;
    for (int i = 0; i < n; i++) {
        char cur = s[i];
        
        if (cur == 'A') {
            int l = 0, r = 51;
            while (l < r) {
                int mid = (l + r) / 2;
                s[i] = c[mid];
                ask(s);
                if (res == "<") {
                    l = mid + 1;
                }
                else {
                    r = mid;
                }
            }
            s[i] = c[l];
            ask(s);
            if (res == "<")
                ans[i] = 'A';
            else         
                ans[i] = c[l];
        }
        else {
            int l = 0, r = 51;
            while (l < r) {
                int mid = (l + r) / 2;
                s[i] = c[mid];
                ask(s);
                if (res == "<") {
                    l = mid + 1;
                }
                else {
                    r = mid;
                }
            }
            ans[i] = c[l];
        }

        s[i] = cur;

        if (i == lst) {
            s[i] = 'A';
        }              
    }    

    found(ans);

    return 0;
}
