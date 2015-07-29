#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned int ui;

ui make(char* s)
{
	int pos = 0;

	int a, b, c, d;
	
	char e, f, g;

	sscanf(s, "%d%c%d%c%d%c%d", &a, &e, &b, &f, &c, &g, &d);

	ui ans = ((a << 8) | b);
	ans <<= 8;
	ans |= c;
	ans <<= 8;
	ans |= d;

	return ans;
}

void out(ui a)
{
	string s;

	for (int i = 0; i < 32; i++)	
		{
			s += (a & 1) + '0';
			a >>= 1;
		}

	reverse(s.begin() ,s.end());

	cout << s << endl;	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	vector <ui> a(n);

	char s[20];

	for (int i = 0; i < n; i++)
		{
		    scanf("%s", s);

			a[i] = make(s);

			//out(a[i]);

			//cout << a[i] << endl;
		}

	//cout << endl;	

	int m;

	cin >> m;

	char s1[20];

	for (int i = 0; i < m; i++)
		{
			scanf("%s%s", s, s1);
			
			ui a1 = make(s);
			ui a2 = make(s1);

			//out(a1);
			//out(a2);

			//cout << endl;

			int ans = 0;

			for (int j = 0; j < n; j++)
				{
					if ((a1 & a[j]) == (a2 & a[j]))
						ans++;
				}

			cout << ans << endl;	
		}

	return 0;
}
