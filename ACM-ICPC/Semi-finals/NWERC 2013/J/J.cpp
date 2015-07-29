#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

typedef struct node* pnode;

struct node {
	pnode l, r, p;
	int tot_twig, tot_ball;
	bool ball;

	node() { }

	node(pnode p, bool ball) : l(NULL), r(NULL), p(p), tot_twig(0), tot_ball(0), ball(ball) {}
};

pnode top, cur;
int total = 0;
int cnt(pnode v) {
	return v ? v -> tot_ball : 0;
}
int ans;

int check(pnode v, int c){
	if (c == 0)
		return 0;
	if (!v) {
		if (c > 0)
			return -1;

		return 0;
	}

	if (v -> tot_twig < c)
		return -1;
	if (!v -> l)
		return c - v->tot_ball;		
	int ans1 = 0, ans = 0;

	if (!(c & 1)) {
		ans = check(v -> l, c >> 1);
		if (ans == -1)
			return -1;

		ans = abs(cnt(v -> l) - (c >> 1));

		ans1 = check(v -> r, c >> 1);

		if (ans1 == -1)
			return -1;

		ans1 = abs(cnt(v -> r) - (c >> 1));

		return ans + ans1;
	} 
	if ((c >> 1) <= v->l->tot_twig && (c >> 1) + 1 <= v->r->tot_twig)
		ans = abs((c >> 1) - v->l->tot_ball) + abs((c >> 1) + 1 - v->r->tot_ball);
	else
		ans = -1;
	if ((c >> 1) + 1 <= v->l->tot_twig && (c >> 1) <= v->r->tot_twig)
		ans1 = abs((c >> 1) + 1 - v->l->tot_ball) + abs((c >> 1) - v->r->tot_ball);
		else
			ans1 = -1;
	if ((ans >= ans1 && ans1 != -1) || (ans1 != -1 && ans == -1)){
		ans = check(v -> l, (c >> 1) + 1);
		if (ans == -1)
			return -1;

		ans = abs(cnt(v -> l) - (c >> 1) - 1);

		ans1 = check(v -> r, (c >> 1));

		if (ans1 == -1)
			return -1;

		ans1 = abs(cnt(v -> r) - (c >> 1));

		return ans + ans1;		
	}
	if ((ans <= ans1 && ans != -1) || (ans != -1 && ans1 == -1)){
		ans = check(v -> l, (c >> 1));
		if (ans == -1)
			return -1;

		ans = abs(cnt(v -> l) - (c >> 1));

		ans1 = check(v -> r, (c >> 1) + 1);

		if (ans1 == -1)
			return -1;

		ans1 = abs(cnt(v -> r) - (c >> 1) - 1);

		return ans + ans1;		
	}
	return -1;	
}

int main(){
	#ifdef Local
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

	string str;
	while (cin >> str) {
		top = new node(NULL, 0);
		cur = top;
		for (size_t i = 1; i < str.size(); ++i){
			if (str[i] == 'B'){
				total++;
				cur->ball = 1;
			}
			else if (str[i] == '('){
				pnode tp = new node(cur, false);
				if (cur->l)
					cur->r = tp;
				else 
					cur->l = tp;
				cur = tp;
			}
			else {
				cur -> tot_ball = cur -> ball + cnt(cur -> l) + cnt(cur -> r);	
				if (cur -> l)
					cur -> tot_twig = cur -> l -> tot_twig + cur -> r -> tot_twig;
				else
					cur -> tot_twig = 1;

				cur = cur -> p;
			}
		}
		int anss = check(top, top->tot_ball);
		if (anss == -1)
			cout << "impossible\n";
		else 
			cout << (anss >> 1) << endl;
	}

	return 0;
}