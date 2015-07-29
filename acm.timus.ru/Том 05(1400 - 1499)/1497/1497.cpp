#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

bool can[1001][1001];

int a[1001][1001];

int n;

bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (a[i][j] == 0 && !can[i][j]) {
				return false;
			}
	}

	return true;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n;

	char c;

	for (int i = 0; i < n; i++) {
		c = getchar();
		
		for (int j = 0; j < n; j++) {
			c = getchar();
			a[i][j] = c - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		int pos = 0;

		while (pos < n && a[i][pos] == 0)
			can[i][pos++] = true;
	}

	if (check()) {
		puts("Yes");
		return 0;
	}
	
	memset(can, false, sizeof can);

	for (int i = 0; i < n; i++) {
	 	int pos = n - 1;
	 	
	 	while (pos >= 0 && a[i][pos] == 0)
	 		can[i][pos--] = true;
   	}

   	if (check()) {
   		puts("Yes");
   		return 0;
   	}

   	memset(can, false, sizeof can);

   	for (int j = 0; j < n; j++) {
   		int pos = 0;

   		while (pos < n && a[pos][j] == 0)
   			can[pos++][j] = true;
   	}

   	if (check()) {
   	  	puts("Yes");
   	  	return 0;
   	  	
   	}	

   	memset(can, false, sizeof can);


   	for (int j = 0; j < n; j++) {
   		int pos = n - 1;

   		while (pos >= 0 && a[pos][j] == 0)
   			can[pos--][j] = true;
   	}

   	if (check()) {
   		puts("Yes");
   		return 0;
   	}

   	puts("No");
   	return 0;
}