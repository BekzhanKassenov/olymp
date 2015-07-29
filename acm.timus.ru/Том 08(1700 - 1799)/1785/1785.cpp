#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	if (n <= 4)
		{
			cout << "few" << endl;
			return 0;
		}

	if (n <= 9)
		{
			cout << "several" << endl;
			return 0;
		}

	if (n <= 19)
		{
			cout << "pack" << endl;
			return 0;
		}

	if (n <= 49)
		{
			cout << "lots" << endl;
			return 0;
		}

	if (n <= 99)
		{
			cout << "horde" << endl;
			return 0;
		}

	if (n <= 249)
		{
			cout << "throng" << endl;
			return 0;
		}

	if (n <= 499)
		{
			cout << "swarm" << endl;
			return 0;
		}	

	if (n <= 999)
		{
			cout << "zounds" << endl;
			return 0;
		}

	cout << "legion" << endl;
	return 0;
}
