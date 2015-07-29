#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

string get_name(string s, int& pos)
{
	int len = s.length();

	string ans;

	ans.clear();

	while (pos < len)
		{
			if (pos < len - 7 && s.substr(pos, 8) == "<friend>")
				{
					pos += 8;

					while (s.substr(pos, 9) != "</friend>")
						ans += s[pos++];

					return ans;
				}
			pos++;
		}

	return ans;	
}

void output(const set <string>& st)
{
	bool flag = false;

	if (st.empty())
		{
			cout << endl;
			return;
		}

	set <string> :: iterator tt = st.end();

	tt--;

	for (set <string> :: iterator it = st.begin(); it != st.end(); it++)
		{
			cout << *it;

			flag = true;
				
			if (it != tt)
				cout << ", ";
			else
				cout << endl;
		}

	if (!flag)
		cout << endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	string tmp;

	getline(cin, tmp);

	map <string, int> m;

	vector <pair <string, set <string> > > a(n); //вектор из пар (имя, его друзья)

	for (int i = 0; i < n; i++)
		{
			getline(cin, a[i].first);

			string s;

			m[a[i].first] = i;

			set <string> st;

			do 
				{
					getline(cin, tmp);
					s += tmp;
				}
			while (tmp.length() < 7 || tmp.substr(tmp.length() - 7, 7) != "</blog>");

			int pos = 0;

			tmp = s;

			int len = tmp.length();

			while (pos < len)
				{
					s = get_name(tmp, pos);

         			if (!s.empty() && s != a[i].first)
         				a[i].second.insert(s);
				}

		}

	for (int i = 0; i < n; i++)
		{
			cout << a[i].first << endl;

			cout << "1: ";

			output(a[i].second);

			cout << "2: ";

			set <string> ans;

			for (int j = 0; j < n; j++)
				if (a[j].second.find(a[i].first) != a[j].second.end())
					ans.insert(a[j].first);

			output(ans);

			cout << "3: ";

			set <string> asn;

			for (set <string> :: iterator it = a[i].second.begin(); it != a[i].second.end(); it++)
				if (a[m[*it]].second.find(a[i].first) != a[m[*it]].second.end())
					asn.insert(*it);

			output(asn);

			cout << endl;
	  }

	return 0;
}
