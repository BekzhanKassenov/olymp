#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

char a[80];

int pos;

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	int mx = 0;

	for (int i = 0; i < 80; i++)
		a[i] = ' ' ;

	while (getline(cin, s))
		{
			for (int i = 0; i < (int) s.length(); i++)
				{
					if (s[i] == '>')
						{
							pos++;
							
							if (pos >= 80)
								pos = 0;

							mx = max(mx, pos);

							continue;
						}

					if (s[i] == '<')
						{
							pos--;

							if (pos < 0)
								pos = 0;

							mx = max(mx, pos);
							
							continue;
						}
					a[pos] = s[i];
					
					pos++;
					
					if (pos >= 80)
						pos = 0;
					
					mx = max(mx, pos);
				}
		}

	for (int i = 0; i < 80; i++)
		cout << a[i];

	cout << endl;

	return 0;
}
