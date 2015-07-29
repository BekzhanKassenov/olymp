#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

typedef struct Tree* PTree;

struct Tree
{
	int prior, cnt;

	int key;

	PTree l, r;

	Tree() {}

	Tree(int key) : prior((rand() << 16) + rand()), cnt(1), key(key), l(NULL), r(NULL) {} 
};

long long ans;

void output(PTree t)
{
	if (!t)
		return;

	output(t -> l);

	cout << t -> key << endl;

	output(t -> r);
}

int cnt(PTree t)
{
	return (t ? t -> cnt : 0);
}

void upd_cnt(PTree &t)
{
	if (!t)
		return;

	t -> cnt = 1 + cnt(t -> l) + cnt(t -> r);
}
                                      
void split(PTree t, int key, PTree &l, PTree &r)
{
	if (!t)
		{
			l = r = NULL;
			return;
		}

	if (t -> key >= key)
		{
			split(t -> l, key, l, t -> l);
			r = t;
		}	
	else
		{
			split(t -> r, key, t -> r, r);
			l = t;
		}	

	upd_cnt(t);
}

void merge(PTree &t, PTree l, PTree r)
{
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

void query(PTree &t, int key, int c)
{
	PTree p1, p2;

	split(t, key, p1, p2);

	/*cout << "SALE " << key  << ' ' << c << endl;

	output(p2);

	cout << endl;

	cout << ans << ' ' ;*/

  	ans += max(min(cnt(p2), c), 0);

  	//cout << ans << endl;

  	//cout << ans << endl;

  	merge(t, p1, p2);
}

void insert(PTree &t, PTree it)
{
	if (!t)
		{
			t = it;
			return;
		}

	if (it -> prior > t -> prior)
		{
			split(t, it -> key, it -> l, it -> r);

			t = it;

			upd_cnt(t);
			
			return;
		}

	if (it -> key < t -> key)
		insert(t -> l, it);
	else
		insert(t -> r, it);

	upd_cnt(t);
}

void erase(PTree &t, int key)
{
	if (!t)
		return;

	if (t -> key == key)
		{
			merge(t, t -> l, t -> r);
			upd_cnt(t);
			return;
		}

	if (t -> key < key)
		erase(t -> r, key);
	else
		erase(t -> l, key);

	upd_cnt(t);	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	string s;

	srand(time(NULL));

	PTree t = NULL;

	while (cin >> s)
		{
			if (s == "QUIT")
				break;

			if (s == "BID")
				{
					double d;

					cin >> d;

					PTree tmp = new Tree((int(d * 100 + 0.01)));

					insert(t, tmp); 

					/*cout << "BID " << d << endl;
               
               output(t);

					cout << endl; */
				}

			if (s == "DEL")
				{
					double d;

					cin >> d;

					erase(t, (int)((d * 100) + 0.01));

					/*cout << "ERASE " << d << endl;

					output(t);*/
				}	
					
			if (s == "SALE")
				{
					int x, c;

					double d;

					cin >> d >> c;

					x = (int)(d * 100 + 0.1);

					query(t, x, c);
				}

		}

	printf("%.2lf", (double(ans)) * 0.01);	
}
