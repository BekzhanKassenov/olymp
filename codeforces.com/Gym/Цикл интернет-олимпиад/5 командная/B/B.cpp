/********************************************
***     Solution by Bekzhan Kassenov      ***
********************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define sqr(x) (x) * (x)
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define ll long long
#define ull unsigned long long
#define INF
#define MOD
#define EPS
#define File "kenobi"

struct item
{
	int val;
	item *pred, *next;

	item(item *a)
		{
			val = a -> val;
			pred = a -> pred;
			next = a -> next;
		}

	item()
		{
			pred = NULL, next = NULL;
		}

	item(int v, item *a)
		{
			next = NULL;
			pred = a;
			val = v;
		}
};

typedef item * pitem;

pitem beg = NULL, en = NULL, middle = NULL;

int size;

void add(int val)
{
	if (size == 0)	
		{
			beg = new item();

			beg -> val = val;
			en = middle = beg;
			return;
		}

	pitem tmp = new item(val, en);
	
	en -> next = tmp;
	
	en = tmp;
}

void take()
{
	if (size == 0)
		return;	

	if (size == 1)
		{
			delete beg;
			delete en;
			beg = en = middle = NULL;
		}

	pitem tmp = en -> pred;
	tmp -> next = NULL;

	delete en;
	en = tmp;
}

void mum()
{
	if (size < 2)
		return;

	pitem nen = middle -> pred;
	middle -> pred = NULL;
	nen -> next = NULL;

	beg -> pred = en;
	en -> next = beg;

	swap(beg, middle);

	if (size % 2)
		middle = en;

	en = nen;
}

void print()
{
	printf("%d\n", size);

	for (pitem it = beg; it != NULL; it = it -> next)
	   printf("%d ", it -> val);
		
	printf("\n");
}

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;

	scanf("%d", &n);

	size = 0;

	int tmp;

	char s[4];

	for (int i = 0; i < n; i++)
		{
		   scanf("\n%s", s);

			if (s[0] == 'a')
				{
					scanf("%d", &tmp);

					add(tmp);
					size++;
					if (size % 2 == 0)
						middle = middle -> next;
				}

			if (s[0] == 't')
				{
					if (size > 0)
						{
							if (size % 2 == 0)
								middle = middle -> pred;

							take();
							size--;
					   }
				}

			if (s[0] == 'm')
				{
					mum();
				}
		}

	print();

	return 0;
}
