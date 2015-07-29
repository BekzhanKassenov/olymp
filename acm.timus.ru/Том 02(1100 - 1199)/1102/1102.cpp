#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool check(string& s)
{
	
}

int main()
{	
	int n;
	
	cin >> n;

	string s;

	while (n--)
		{
			cin >> s;

			if (check(s))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;

		}
}
