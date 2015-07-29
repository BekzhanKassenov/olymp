#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

const int MAXN = 100100;

char s[MAXN], temp[MAXN];
int n;

inline void erase_first(char s[]) {
 	for (int i = 0; s[i]; i++) {
 	 	s[i] = s[i + 1];
 	}
}

inline bool simple_check(int l, int r) {
 	while (l < r) {
 		if (s[l] != s[r]) {
 		 	return false;
 		}

 		l++, r--;
 	}

 	return true;
}

inline bool palindrome(int l, int r) {
 	if (l >= r)
 		return true;

 	if (s[l] == s[r] && palindrome(l + 1, r - 1))
 		return true;

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

	gets(temp);
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
