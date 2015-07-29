#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

main()
{
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;

	cin >> n;

	string a, b;
	
	cin  >> a >> b;

	for (int l = n, i = -1; i++ < l; b = b.substr(1, l - 1) + b[0])
		if (b == a)
			{
				cout << i;
				return 0;
			}

	cout << -1;

	return 0;
}
