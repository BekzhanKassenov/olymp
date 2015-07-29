#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>                                       
#include <math.h>

using namespace std;

int len;

string get_name(const string& s, int& pos)
{
	pos = 1;
	
	string ans;

	ans += s[0];

	do
		{
			ans += s[pos];
		}
	while (s[pos++] != '"' && pos < len);

	return ans;	
}

int str_to_int(string s)
{
	int ans = 0;

	for (size_t i = 0; i < s.size(); i++)
		ans = ans * 10 + s[i] - '0';

	return ans;	
}

int get_int(const string& s, int& pos)
{
	while (s[pos] > '9' || s[pos] < '0' && pos < len)
		pos++;

	string ans;

	while (s[pos] >= '0' && s[pos] <= '9' && pos < len)
		ans += s[pos++];

	return str_to_int(ans);	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	string ans;

	int x1, y1, x2, y2, tmt, anst = -1;

	char c;

	getline(cin, ans);

	for (int i = 0; i < n; i++)
		{
		    string s;

		    getline(cin, s);

		    len = s.size();

		    int pos = 0;

		    string name = get_name(s, pos);

		    x1 = get_int(s, pos);
		    y1 = get_int(s, pos);

		    x2 = get_int(s, pos);
		    y2 = get_int(s, pos);

			x1 = x1 * 60 + y1;
			x2 = x2 * 60 + y2;

			tmt = x2 - x1;

			if (tmt <= 0)
				tmt += 60 * 24;

			if (anst == -1 || anst > tmt)
				{
					anst = tmt;
					ans = name;
				}

		}

  	double tmp =  double((650.0 * 60) / (double(anst)));

  	int h;

  	if (tmp - (int)(tmp) < 0.5)
  		h = (int)tmp;
  	else
  		h = (int)tmp + 1;	

  	cout << "The fastest train is " << ans << '.' << endl;
  	printf("It's speed is %d km/h, approximately.", h);

  	return 0;
}
