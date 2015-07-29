#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

int k, n, m, from, to, type, tmp;

struct que {
 	int q[100];

 	int head, tail;

 	que() : head(0), tail(0) {}

 	bool empty() {
 		return (head >= tail);
 	}

 	void push(int n) {
 		q[tail++] = n;
 	}

 	int front() {
 	  	return q[head];
 	}

 	void pop() {
 		head++;
 	}

 	void clear() {
 		head = tail = 0;
 	}
} q;

int g[35][35];

bool try_bfs(int mask) {
	int used = 1;

	q.clear();

	q.push(0);
	int cur;

	while (!q.empty()) {
		cur = q.front();
		
		if (!(cur ^ 1))
			break;
		
		q.pop();

		for (int i = 0; i < n; i++) {
			if ((mask & g[cur][i]) && !(used & (1 << i))) {
				used |= 1 << i;
				q.push(i);
			}
		}
	}

	return (used & 2);
}

bool u[1 << 20];

char res[1000];
int sz;
stringstream ss;

void print(int n) {
 	if (!n)
 		return;

 	print(n / 10);
 	res[sz++] = n % 10 + '0';
}

void print_int(int n, char razd) {
	if (!n) 
		res[sz++] = '0';
	else
		print(n);

	res[sz++] = razd;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d%d%d", &k, &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &from, &to, &type);
		g[from][to] |= (1 << type);
		g[to][from] |= (1 << type);
	}

	int ans = n, ans_m = (1 << k) - 1;

	for (int mask = (1 << k) - 1; mask >= 0; mask--) {
	 	if (u[mask] || __builtin_popcount(mask) > ans)
	 		continue;

	 	if (try_bfs(mask)) {
	 		if (ans > __builtin_popcount(mask)) {
	 	 		ans_m = mask;
	 	 		ans = __builtin_popcount(mask);
			}
		} else {
			tmp = mask;

			while (tmp) {
				u[tmp] = true;
				tmp = mask & (tmp - 1);
			}
		}  
	}

	//print_int(ans, '\n');

	ss << ans << endl;

	for (int i = 0; i < k; i++)
		if (ans_m & (1 << i))
			ss << i << ' ';

	cout << ss.str();

	return 0;
}