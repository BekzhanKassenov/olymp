/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()
#define File "compression"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

typedef struct Node* pNode;

struct Node {
    pNode sib, lc, rc;
    char cur;
	char c;

	Node(char cur): cur(cur) {
		lc = rc = sib = NULL;
		c = 0;
	}
};

int q = 0;
pNode root;

void add(const string& s) {
	pNode cur = root;

	for (size_t i = 0; i < s.size(); i++) {
		pNode next = NULL;

		for (pNode j = cur -> lc; j != NULL; j = j -> sib) {
			if (j -> cur == s[i]) {
				next = j;
				break;
			}
		}

		if (next == NULL) {
			if (cur -> lc) {
				cur -> rc -> sib = new Node(s[i]);
				cur -> rc = cur -> rc -> sib;
			} else {
				cur -> lc = new Node(s[i]);
				cur -> rc = cur -> lc;
			}
			q++;
			next = cur -> rc;
		}
		cur = next;	
	}

	cur -> c |= 1;
}

ll dfs(pNode v, int gl = 0) {
	if ((v -> c) & 1) {
		v -> c |= 2;
		return (1ll << (40 - gl));
	}

	ll ans = 0;

	for (pNode i = v -> lc; i != NULL; i = i -> sib)
		ans += dfs(i, gl + 1);

	if ((root != v) && ans >= (1ll << (40 - gl))) {
		v -> c |= 2;
		return (1ll << (40 - gl));
	}

	return ans;
}

char res[50];

int cnt = 0;

void dfs1(pNode v) {
 	if ((v -> c) & 2) {
 		cnt++;
 		return;
 	}

 	for (pNode i = v -> lc; i != NULL; i = i -> sib) 
 		dfs1(i);
}

void dfs2(pNode v, int gl = 0) {
	if ((v -> c) & 2) {
		res[gl] = '\0';
		printf("%s\n", res);
		return;
	}

	for (pNode i = v -> lc; i != NULL; i = i -> sib) {
		res[gl] = i -> cur;
		dfs2(i, gl + 1);
	}
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;

	cin >> n;

	string s;

	getline(cin, s);

	root = new Node(0);

	for (int i = 0; i < n; i++) {
		getline(cin, s);
		add(s);
	}

	ll ans = dfs(root);
	dfs1(root);

	cout << ans << endl << cnt << endl;
	
	dfs2(root);

	return 0;
}
