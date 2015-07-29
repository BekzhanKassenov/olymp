#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int n;

	cin >> n;

	string s;

	while (n)	
		{
			s += n % 3 + '0';
			n /= 3;
		}

	reverse(s.begin(), s.end());

	int len = s.length();	

	for (;;)
		{
			bool flag = true;

			for (int i = 1; i < len; i++)
				{
					if (s[i] == '0')
						{
							s[i - 1]--;
							s[i] = '3';
							flag = false;
						}
				}

			if (flag)
				break;	
		}

	while (s[0] == '0')
		s.erase(s.begin());

	cout << s << endl;
	fclose(stdout);	
	return 0;
}
