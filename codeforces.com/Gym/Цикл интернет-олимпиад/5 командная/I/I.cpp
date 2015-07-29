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
#define File "yoda"

string s;

int len;

string get_word(int &pos)
{
	pos++;

	string ans;

	while (s[pos] >= 'a' && s[pos] <= 'z' && pos < len)
		ans += s[pos++];

	return ans;
}

vector <string> get_predl(int &pos)
{
	if (pos != -1)
		pos++;
	
	vector <string> ans;

	while (s[pos] != '.' && pos < len)
		ans.push_back(get_word(pos));

	return ans;
}

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	getline(cin, s);

	int pos = -1;
   
   len = s.length();

   bool flag = false;

	while (pos < len)
		{
			vector <string> a = get_predl(pos);

			if (!flag)
				flag = true;
			else
				cout << ' ';	

			for (int i = a.size() - 1; i >= 0; i--)
				{
					cout << a[i];
					if (i == 0)
						cout << '.';
					else
						cout << ' ';
				}	
		}

	return 0;
}
