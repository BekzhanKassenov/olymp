/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 300010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int get_prior() {
	static vector <int> priorities(MAXN);
	static int last_response = 0;
	static bool initialized = false;

	if (!initialized) {
	 	for (int i = 0; i < MAXN; i++) {
	 	 	priorities[i] = i;
	 	}
	 	srand(time(NULL));
	 	random_shuffle(all(priorities));
	 	initialized = true;
	}

	return priorities[last_response++];
}

struct Node {
  	long long sum;
  	int key, prior;
  	Node *left, *right;

  	Node() : sum(0), 
  			 key(0), 
  			 prior(get_prior()), 
  			 left(NULL), 
  			 right(NULL) { }

  	Node(int key) : sum((long long) key), 
  					key(key), 
  					prior(get_prior()), 
  					left(NULL), 
  					right(NULL) { }
};

typedef Node* pNode;

void output(pNode ver) {
 	if (ver == NULL) {
 	 	return;
 	}

 	output(ver->left);
 	cerr << ver -> key << ' ';
 	output(ver->right);
}

long long get_sum(const pNode ver) {
 	if (ver != NULL)
 		return ver->sum;

 	return 0;
}

void update_sum(const pNode ver) {
 	if (ver != NULL) {
 	 	ver->sum = ver->key + get_sum(ver->left) + get_sum(ver->right);
 	}
}

void split(pNode ver, pNode& l, pNode& r, int key) {
	if (ver == NULL) {
		l = NULL;
		r = NULL;
		return;
	}

	if (key < ver->key) {
		split(ver->left, l, ver->left, key);
		r = ver;
	} else {
		split(ver->right, ver->right, r, key);
		l = ver;
	}

	update_sum(ver);
	update_sum(l);
	update_sum(r);
}

pNode merge(pNode l, pNode r) {
	if (l == NULL || r == NULL) {
		return (l == NULL) ? r : l;
	}

	pNode result = NULL;
	if (l->prior > r->prior) {
		l->right = merge(l->right, r);
		result = l;
	} else {
		r->left = merge(l, r->left);
		result = r;
	}

	update_sum(l);
	update_sum(r);
	return result;
}

bool find(pNode ver, pNode item) {
 	if (ver == NULL) {
 		return false;
	}

	if (ver->key == item->key) {
	 	return true;
	}

	if (ver->key < item->key) {
	 	return find(ver->right, item);
	}

	return find(ver->left, item);
}

void insert(pNode& ver, pNode item) {
	if (ver == NULL) {
		ver = item;
		update_sum(ver);
		return;
	}
	
	if (ver->prior < item->prior) {
		split(ver, item->left, item->right, item->key);
		ver = item;
	} else if (item->key < ver->key) {
		insert(ver->left, item);
	} else {
		insert(ver->right, item);
	}

	update_sum(ver);
}

pNode root = NULL;

long long sum(int l, int r) {
	pNode temp1, temp2, temp3;
	split(root, temp1, temp2, l - 1);
	split(temp2, temp2, temp3, r);

	long long result = get_sum(temp2);
	/*
	fprintf(stderr, "SUM: l=%d r=%d result=%I64d\n", l, r, result);
	output(temp2);
	cerr << endl << endl;
	*/
	root = merge(temp1, temp2);
	root = merge(root, temp3);

	return result;
}

int n;
char type;
int x, l, r;
bool prev_query = false;
long long prev_ans;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    scanf("%d\n", &n);

    while (n--) {
    	scanf("%c ", &type);
    	if (type == '?') {
    		scanf("%d %d\n", &l, &r);
    		prev_ans = sum(l, r);
    		prev_query = true;
    		printf("%I64d\n", prev_ans);
    	} else {
    		scanf("%d\n", &x);
    		pNode temp = new Node(x);
    		if (prev_query) {
    			temp->key += prev_ans % MOD;
    			temp->key %= MOD;
    		}

    		prev_query = false;
    		if (!find(root, temp)) {
    			insert(root, temp);
			}
    	}

    	//output(root);
    	//cerr << endl;
    }

    return 0;
}
