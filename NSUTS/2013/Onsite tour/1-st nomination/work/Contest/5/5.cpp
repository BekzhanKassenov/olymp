#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cstring>
#include <cassert>
#include <cmath>
#include <bitset>

using namespace std;

int n, m;
int num[1000100];
int x;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		num[x]++;
	}

	for (int i = 1; i <= 100000; i++) {
		if (num[i] % m != 0) {
			puts("ARGH!!1");
			return 0;
		}
	}

	puts("OK");

	return 0;
}

