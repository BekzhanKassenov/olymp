/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define sqr(x) (x) * (x)
#define INF (int) (2e9)
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

typedef struct Tree* PTree;

int n, m;

struct Tree
{
	int key, prior, flag, cnt;

	PTree l, r;

	Tree() {}

	Tree(int key) : flag(0), key(key), cnt(1), prior((rand() << 16) + rand()), l(NULL), r(NULL) {}
};

void push(PTree& t)
{
	if (!t)
		return;

	t -> key += t -> flag;

	if (t -> l)
		t -> l -> flag += t -> flag;

	if (t -> r)
		t -> r -> flag += t -> flag;

	t -> flag = 0;	
}

int cnt(PTree t)
{
	return t ? t -> cnt : 0;
}

void upd_cnt(PTree& t)
{
	if (t)
		t -> cnt = 1 + cnt(t -> l) + cnt(t -> r);
}

void split(PTree t, PTree& l, PTree& r, int key, int add = 0)
{
	if (!t)
		{
			l = r = NULL;
			return;
		}

	push(t);

	int cur = cnt(t -> l) + add;

	if (cur >= key)
		{
			split(t -> l, l, t -> l, key, add);
			r = t;
		}
	else
		{
			split(t -> r, t -> r, r, key, cur + 1);
			l = t;
		}

	upd_cnt(t);
}

void merge(PTree& t, PTree l, PTree r)
{
	push(l);
	push(r);
	if (!l || !r)
		{
			t = l ? l : r;
			upd_cnt(t);
			return;
		}

	if (l -> prior > r -> prior)
		{
			merge(l -> r, l -> r, r);
			t = l;
		}
	else
		{
			merge(r -> l, l, r -> l);
			t = r;
		}	

	upd_cnt(t);
}

void upd(PTree t, int l, int r)
{
	PTree t1, t2, t3;

	split(t, t1, t2, l);
	split(t2, t2, t3, r - l + 1);

	t2 -> flag = 1;

	merge(t, t1, t2);

	merge(t, t, t3);
}

void make(PTree t, vector <int>& a)
{
	if (!t)
		return;

	push(t);

	make(t -> l, a);

	a.push_back(t -> key);

	make(t -> r, a);
}

vector <int> a, v;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n >> m;

	srand(time(NULL));

	a.resize(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	PTree t = NULL;

	for (int i = 0; i < n; i++)
		{
			PTree it = new Tree(0);
			merge(t, t, it);
		}

	for (int i = 0; i < m; i++)
		{
			int l, r;

			cin >> l >> r;

			l--, r--;

			upd(t, l, r);
		}	

	make(t, v);

	sort(v.rbegin(), v.rend());

	sort(a.rbegin(), a.rend());

	long long ans = 0;

	for (int i = 0; i < n; i++)
		{
			ans += a[i] * 1ll * v[i];
		}

	cout << ans;	
	return 0;
}
