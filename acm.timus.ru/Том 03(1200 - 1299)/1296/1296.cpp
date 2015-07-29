#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	int x;

	int sum = 0, Max = 0;

	for (int i = 0; i < n; i++)
		{
			cin >> x;

			sum += x;

			Max = max(sum, Max);

			if (sum < 0)
				sum = 0;
		}

	cout << Max;

	return 0;
}
