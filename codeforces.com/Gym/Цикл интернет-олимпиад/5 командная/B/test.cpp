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

deque <int> a[2];

int cur = 0;

void take()
{
	if (size == 0)
		return;

	if (size == 1)
		{
			a[cur].pop_back();
			return;
		}

	a[cur].pop_back();
	
	size--;
	
	if (size % 2)
		{
			a[!cur].
		}
}

void mum()
{
}

void print()
{
	cout << size << endl;

	for (pitem it = begin; it != NULL; it = it -> next)
		cout << it -> val << ' ';

	cout << endl;
}

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	ios_base :: sync_with_stdio(false);

	int n;

	cin >> n;

	size = 0;

	string s;

	int tmp;

	for (int i = 0; i < n; i++)
		{
		   cin >> s;

			if (s == "add")
				{
					cin >> tmp;
					
					add(tmp);
					size++;
					if (size % 2 == 0)
						middle = middle -> next;
				}

			if (s == "take")
				{
					if (size != 0)
						{
							if (size % 2 == 0)
								middle = middle -> pred;

							take();
							size--;
					   }
				}

			if (s == "mum!")
				{
					mum();
				}

			//print();

		}

	print();

	return 0;
}
