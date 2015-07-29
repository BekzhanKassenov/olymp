#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

struct proc
{
	string name;
	vector <string> vars;
};

vector <proc> p;
vector <pair <string, string> > vars;

proc analyse(string s)
{
	string a;
	for (int i = 0; i < s.length(); i++)
		if (s[i]!=' ')
			a += s[i];
	if (a.substr(0, 4) == "void")
		a = a.substr(4, a.length() - 4);
	string n;
	proc ans;
	int i = 0;
	int len = a.length();
	while (a[i] != '(' && i < len)
		{
			n += a[i];
			i ++;
		}
	i++;
	ans.name = n;

	while (i < len)
		{
			n = "";
			while (a[i] != ',' && a[i] != ')' && i < len)
				{
					n += a[i];
					i++;
				}
			ans.vars.push_back(n);
			if (a[i] == ')')
				break;
			i++;
		}
	return ans;			
}

void writeln(proc n)
{
	cout << "NAME: " << n.name << endl;
	cout << "VARS:" << endl;
	for (int i = 0; i < n.vars.size(); i++)
		cout << n.vars[i] << endl;
}

bool operator == (proc a, proc b)
{
	if (a.name != b.name)
		return false;
	if (a.vars.size() != b.vars.size())
		return false;
	for (int i = 0; i < a.vars.size(); i++)
		if (a.vars[i] != b.vars[i] && a.vars[i] != "T")
			return false;
	return true;	
}

int analyse2(proc a)
{
	int ans = 0;
	for (int i = 0; i < p.size(); i++)
		if (p[i] == a)
			ans++;
	return ans;
}

int main()
{
//	freopen("input.txt","r",stdin);
	
	int n,m;
	cin >> n;
	string s;
	
	getline(cin,s);
	
	for (int i = 0; i < n; i++)
		{
			getline(cin, s);
			p.push_back(analyse(s));
		}
	
	/*for (int i = 0; i < n; i++)
		writeln(p[i]);*/
	
	cin >> m;
	
	vars.resize(m);
	
	for (int i = 0; i < m; i++)
		cin >> vars[i].first >> vars[i].second;
	
	cin >> n;

	proc k;

	getline(cin,s);

	for (int i = 0; i < n; i++)
		{
			getline (cin, s);
			k = analyse(s);
//			writeln(k);
			for (int i = 0; i < k.vars.size(); i++)
				{
					for (int j = 0; j < m; j++)
						if (vars[j].second == k.vars[i])
							{
								k.vars[i] = vars[j].first;
								break;
							}
				}
//			writeln(k);
			cout << analyse2(k) << endl;
		}

	return 0;
}
