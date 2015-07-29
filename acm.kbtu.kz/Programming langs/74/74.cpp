#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;

	while (cin >> s)
		{
			int len =  (int)s.length();

			for (int i = 0; i <= len - 4; i++)
				{
					if (s.substr(i, 4) == "1543")
						{
							cout << "URA";
							return 0;
						}
				}
		}
	cout << "NO";
	return 0;
}
