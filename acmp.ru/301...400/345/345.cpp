#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

#define INF 10000

vector <vector <int> > g;

vector <bool> used, inst, ans;

stack <int> st;

int n;

void init()
{
	g.resize(n);
	ans.resize(n, false);
}

void read()
{
	map <string, int> m;

	int cnt = 0;

	cin >> n;

	init();

	string c;

	getline(cin, c);

	vector <vector <string> > tmp(n);	

	for (int i = 0; i < n; i++)
		{
			string name;

			getline(cin, name);

			int k;

			cin >> k;

			m[name] = i;

			getline(cin, c);

			for (int j = 0; j < k; j++)
				{
					string s;

					getline(cin, s);

					tmp[i].push_back(s);
				}
			getline(cin, c);
		}

	for (int i = 0; i < n; i++)
		{
			g[i].resize(tmp[i].size());
			for (size_t j = 0; j < tmp[i].size(); j++)
				{
					g[i][j] = m[tmp[i][j]];
				}
		}
}

void dfs(int v)
{
	used[v] = true;

	inst[v] = true;

	st.push(v);

	for (size_t i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];

			if (!used[to])
				dfs(to);
			else
				{
					if (inst[to])
						{
							stack <int> tmp = st;

							while (!tmp.empty())
								{
									ans[tmp.top()] = true;
									if (tmp.top() == to)
										break;
									tmp.pop();
								}
						}
				}		
					
		}
	inst[v] = false;
	st.pop();
}

void get_ans(int v)
{
	used.assign(n, false);
	inst.assign(n, false);
	dfs(v);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	read();

	for (int i = 0; i < n; i++)
		{
			
			if (ans[i])
				cout << "YES" << endl;
			else
				{
					get_ans(i);

					if (ans[i])
						cout << "YES" << endl;
					else
						cout << "NO" << endl;
				}
		}

	return 0;	
}