#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

struct team
{
	int points, wins, looses, games, zab, prop;

	team() : points(0), wins(0), looses(0), games(0), zab(0), prop(0) {}
};

map <string, team> m;

int read = 0;

string get_name(string &s, int &pos)
{
	string ans;

	while (s[pos] >= 'A' && s[pos] <= 'Z')
		ans += s[pos++];

	pos++;

	return ans;
}

int str_to_int(string q)
{
	int ans = 0;

	for (int i = 0; i < (int)q.length(); i++)
		ans = ans * 10 + q[i] - '0';

	return ans;
}

int get_int(string &s, int &pos)
{
	string ans;

	while (s[pos] >= '0' && s[pos] <= '9' && pos < (int)s.length())
		ans += s[pos++];

	pos++;

	return str_to_int(ans);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	for (int i = 0; i < 5; i++)
		{
			string s;

			getline(cin, s);

			int pos = 0;

			string team1 = get_name(s, pos);
			string team2 = get_name(s, pos);

			int c1 = get_int(s, pos);
			int c2 = get_int(s, pos);

			if (m[
		}
}
