#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 100010;

int l[maxn], r[laxn], n, a, b, x;
bool used[maxn];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
   	#endif

   	scanf("%d", &n);

   	for (int i = 0; i < n; i++) {
   		scanf("%d", &l[i]);
   		l[i]--;
   		r[i] = l[i];

   		while (scanf("%d", &x) && x != 0)
   			r[i] = x - 1; 
   	}
   	
   	scanf("%d%d", &a, &b);
   	a--, b--;

   	vector <int> path_a, path_b;

   	while (true) {
   		path_a.push_back(a);
   		used[a] = true;
   		a = l[a];
   		if (used[a])
   			break;
   	}

   	memset(used, 0, sizeof used);

   	while (true) {
   		path_b.push_back(b);
   		used[b] = true;
   		b = r[b];
   		if (used[b])
   			break;
   	}


}
