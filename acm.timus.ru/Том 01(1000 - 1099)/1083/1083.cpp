#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string s;

	cin >> s;

	int k = (int)s.length();

	int ans = n;

	bool flag = false;

	for (;;)	
		{
			n -= k;

			if (n <= 0)
				break;

			ans *= n;		
		}
  	cout << ans;
  	return 0;
}

