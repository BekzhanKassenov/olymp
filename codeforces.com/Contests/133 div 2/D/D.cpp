#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct sektor
{
	vector <int> l, r;
	vector <int> perem;
};

int n;

int left(int k)
{
	return ((k == 0) ? (n - 1) : (--k));
}

int right(int k)
{
	return ((k == n - 1) ? (0) : (++k));
}



int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	cin >> n;

	vector <sektor> a(n);


}
