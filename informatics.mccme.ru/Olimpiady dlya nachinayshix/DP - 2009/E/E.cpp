#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string ans;
	while (n)
		{
			if (n % 4 == 0)
				{
					ans += '4'; 
					n /= 4;
				}
			else
				{
					ans += '1';
					n--;
				}
		}
	for (int i = ans.size() - 1; i >= 0; i --)
		{
			cout << ans[i];
			if (i != 0)	
				cout << ' ';
		}
	return 0;
}
