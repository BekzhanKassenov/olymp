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

string s;

int len;

void get_next(int &pos)
{
	for (; pos < len; pos++)
		if (s[pos] == ':' && pos != 0)
			break;
}

string analyse()
{
	vector <string> q(8);;

	int pos = 0;

	int uk = 0;

	int p = 0;

	while (p < len)
		{
			int k = p;
			get_next(p);

			if (s[p] == ':' && p > 0 && s[p - 1] == ':')
				{
					string ans;
					q.push_back(ans);
				}

			if (s[k] != ':')
				{
				//	cout << k << ' ' << s[k] << endl;

					for (int i = k; i < p; i++)
						q[uk] += s[i];
			   }
		//	cout << q[uk] << endl;

			p++;

			uk++;
		}

	int cnt = uk;

	int nm = 8 - cnt + 1;

	//cout << nm << ' ' << cnt <<  endl;

	for (int i = 0; i < cnt; i++)
		{
		 	if (q[i].empty())
		 		{
		 			for (int j = 0; j < nm; j++)
		 				q[i] += ":0000";

		 			break;
		 		}
		}

	for (int i = 0; i < cnt; i++)
		{
			int l = q[i].length();

			if (l < 4)
				{
					string res = ":";
					for (int j = 0; j < 4 - l; j++)
						res += "0"; 

					res += q[i];

					q[i] = res;
				}

			else
				if (l == 4)
					q[i] = ":" + q[i];
		}

	string ans;

	for (int i = 0; i < cnt; i++)
		ans += q[i];

	if (ans[0] == ':')
		ans.erase(ans.begin());

	return ans;	

}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		{
			cin >> s;
			len = s.length();
			cout << analyse() << endl;
	  	}

	return 0;
}
