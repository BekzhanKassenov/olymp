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

typedef struct Trie* PTrie;

struct Trie
{
	bool leaf;

	PTrie next[2];

	Trie(bool leaf) : leaf(leaf), next[0](NULL), next[1](NULL) {}
};

void push(PTrie root, ll n)
{
	int l = 0;

	while ((1ll << l) <= n)
		{
			int nmb = ((n & (1ll << l)) > 0);

			if (root -> next[nmb] = NULL)
				root -> next[nmb] = new Trie(false);
		
		    root = root -> next[nmb];
		
		    l++;
		}

	root -> leaf = true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: synw_with_stdio(false);

	int n;

	cin >> n;

	vector <long long> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	long long xor_sum = a[0];

	for (int i = 1; i < n; i++)
		xor_sum ^= a[i];

	PTrie root = new Trie();

	push(root, 

	for (int i = n -

	return 0;
}
