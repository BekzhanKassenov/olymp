#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int n;

	cin >> n;

	int l = 2, r = 10;

	for (int i = 0; i < n; i++)
		{
			int k;

			string s;

			cin >> k >> s;

			if (s == "hungry")
				l = max(l, k);
			else
				r = min(r, k);	
		}

   	if (l >= r)
   		cout << "Inconsistent";
   	else
   		cout << r;

   	return 0;	
}
