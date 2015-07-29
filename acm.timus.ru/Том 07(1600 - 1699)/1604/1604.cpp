#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct Item* PItem;

#define F first
#define S second

struct Item {
 	int val;

   	PItem next, prev;

   	Item() : val(0), next(NULL), prev(NULL) {}

   	Item(int val) : val(val), next(NULL), prev(NULL) {}
};

PItem start = NULL, end = NULL;

pair <int, int> a[10010];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int k;

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> a[i].F;
		a[i].S = i;
	}	

	sort(a, a + k);

	reverse(a, a + k);

	PItem cur = start;

	for (int i = 0; i < k; i++) {
	}
}
