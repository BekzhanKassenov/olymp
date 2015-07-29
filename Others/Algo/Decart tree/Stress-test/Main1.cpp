#include <iostream>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	freopen("log", "a", stderr);

	double start = clock();

	ios_base :: sync_with_stdio(false);
	
	int n;

	cin >> n;

	int x;
	char c;

	multiset <int> s;

	for (int i = 0; i < n; i++) {
		cin >> c >> x;

		switch (c) {
			case '+':
				s.insert(x); 
				break;
			case '-':
				s.erase(x);
				break;
			case '?':
				if (s.find(x) != s.end())	
					puts("YES");
				else
					puts("NO");	
		}
	}

	fprintf(stderr, "          %.3lf", double(clock() - start) / CLOCKS_PER_SEC);;

	return 0;
}
