#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	string a, b;
	
	cin  >> a >> b;

	for (int l = a.size(), i = -1; i++ < l; b = b.substr(1, l - 1) + b[0])
		if (b == a)
			{
				cout << i;
				return 0;
			}

	cout << -1;

	return 0;
}
