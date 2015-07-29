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
#define File "t9"

int len, cnt;

struct item
{
	int F, S;
	string str;

	item() {}

	item(int F, int S, string str) : F(F), S(S), str(str) {}
};

bool operator < (const item &a, const item &b)
{
	if (a.F > b.F)
		return true;

	if (a.F < b.F)
		return false;

	if (a.S > b.S)
		return true;

	if (a.S < b.S)
		return false;

	if (a.str < b.str)
		return true;

	return false;	
}

map <string, set <item> > m;

int nmb_for_letter(char c)
{
	if (c >= 'a' && c <= 'c')
		return 2;

	if (c >= 'd' && c <= 'f')
		return 3;

	if (c >= 'g' && c <= 'i')
		return 4;

	if (c >= 'j' && c <= 'l')
		return 5;

	if (c >= 'm' && c <= 'o')
		return 6;

	if (c >= 'p' && c <= 's')
		return 7;

	if (c >= 't' && c <= 'v')
		return 8;

	if (c >= 'w' && c <= 'z')
		return 9;
}

string get_mask(const string &s)
{
 	string ans;

 	for (size_t i = 0; i < s.size(); i++)
 		ans += nmb_for_letter(s[i]) + '0';

 	return ans;
}

bool get_next(const string &s, int &pos)
{
	if (pos == len)
	   return false;

	if (s[pos] == ' ')
		{
			cout << ' ';
			pos++;
			return true;
		}

	if (s[pos] == '1')
		{
			int cn = 1;
			pos++;

			while (pos < len && s[pos] == '*')
				{
					cn++;
					pos++;
				}

			if (cn == 1)
				cout << '.';

			if (cn == 2)
				cout << ',';

			if (cn == 3)
				cout << '?';

			return true;	
		}

	string mask;
	
	while (pos < len && s[pos] >= '2' && s[pos] <= '9')
		mask += s[pos++];

	int cn = 1;

	while (pos < len && s[pos] == '*')
		{
			pos++;
			cn++;
		}

	set <item> :: iterator it = m[mask].begin();

	/*cout << endl << "DEBUG :" << endl;

	for (set <item> :: iterator iter = m[mask].begin(); iter != m[mask].end(); iter++)
		cout << iter -> str << ' ' << iter -> F << ' ' << iter -> S << endl;

	cout << "END OF DEBUG" << endl;*/

	while (--cn > 0)
		it++;

	int prior = it -> F;
	string sr = it -> str;
	
	m[mask].erase(it);

	cout << sr;

	m[mask].insert(item(++prior, ++cnt, sr));
	return true;
}

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;

	cin >> n;

	string s;

	int prior;

	for (int i = 0; i < n; i++)
		{
			cin >> s >> prior;

			m[get_mask(s)].insert(item(prior, 0, s));
		}

	getline(cin, s);

	getline(cin, s);

	len = s.length();

	int pos = 0;

	while (get_next(s, pos));

	return 0;
}
