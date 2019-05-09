#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
#include <map>
 
using namespace std;
 
const int MAXN = 100100;
 
char s[MAXN], temp[MAXN];
int n;
 
inline void erase_first(char s[]) {
    for (int i = 0; s[i]; i++) {
        s[i] = s[i + 1];
    }
}

map <pair <int, int>, bool> mem;  
inline bool simple_check(int l, int r) {
    pair <int, int> entry = make_pair(l, r);
    if (mem.count(entry)) {
        return mem[entry];
    }

    bool& ans = mem[entry];
    if (l >= r) {
        return ans = true;
    }

    if (s[l] == s[r]) {
        return ans = simple_check(l + 1, r - 1);
    }

    return false;
}

inline bool palindrome(int l, int r) {
    if (l >= r)
        return true;
 
    if (s[l] == s[r] && palindrome(l + 1, r - 1)) {
        return true;
    }
 
    if (simple_check(l, r - 1)) {
        erase_first(s + r);
        return true;
    }
 
    if (simple_check(l + 1, r)) {
        erase_first(s + l);
        return true;
    }
 
    if (simple_check(l + 1, r - 1)) {
        s[l] = s[r];
        return true;
    }
 
    return false;
}
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    fgets(temp, MAXN, stdin);
    for (int i = 0; temp[i]; i++)  {    
        if (isalpha(temp[i])) {
            s[n++] = toupper(temp[i]);
        }
    }
 
    s[n] = '\0';
 
    if (palindrome(0, n - 1)) {
        puts("YES");
        puts(s);
    } else {
        puts("NO");
    }
 
    return 0;
}