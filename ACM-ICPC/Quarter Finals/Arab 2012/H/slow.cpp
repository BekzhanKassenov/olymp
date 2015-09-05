//Solution by Zhusupov Nurlan
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

typedef long long LL;
typedef map<string , int> MSI;
typedef vector<int> VI;

#define pb(x) push_back(x)
#define sqr(x) ((x) * (x))
#define SZ(t) ((int) t.size())
#define len(t) ((int) t.length())
#define base 10
#define fname ""
#define sz 1000 * 1000
#define EPS (1e-8)
#define MOD ((int)1e9 + 7)
#define write(xx) printf("%d" , xx);
#define readln(xx) getline(cin , xx)
#define read(xx) scanf("%d" , &xx)
#define for(xx1 , yy1 , zz1) for(int zz1 = xx1 ; zz1 <= yy1 ; zz1++)

const double PI  = acos(-1.0);

LL T, n, k1, k2;
LL S, ans, s, t;
char c;

VI a, b;
bool was[sz];

int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int get(VI a)
{
	int S = 1;

	if (a.size() > 0)
		for (0, a.size() - 1, i)
			S = lcm(a[i], S);	
   	return S;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif	

	cin >> T;

	for (1, T, test)
	{
		cin >> n;
		S = 9;
		for (1, n - 1, i)
			S = S * 10 + 9;
	  	n = S;
		a.clear();
		b.clear();
		for (1, 6, i)
		{
			was[i] = false;
			cin >> c;
			if (c == '0')
				b.pb(i);
		   	else
		   	if (c == '1')
		   		a.pb(i);
		}
		k1 = a.size();
		k2 = b.size();
		ans = 0;
		bool f;

		for (0, n, i)
		{
			f = true;
			for (0, k1 - 1, j)
				if (i % a[j] != 0)
					f = false;

			for (0, k2 - 1, j)
				if (i % b[j] == 0)
					f = false;
			ans += f;
		}
		cout << ans << endl;;
	}
    	return 0;
}