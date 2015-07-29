#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector <int> a(m);

	for (int i = 0; i < m; i++)
		cin >> a[i];

	int i = 0;

	while (i < m)
		{
			if (a[i] == a[i + 1] - 1)
				{
					cout << a[i] << '-';
					while (a[i] + 1 == a[i + 1] && i < m)
						i++;
					cout << a[i];
					if (i < m - 1)
						cout << ',';
					i++;
				}

			else
				{
					cout << a[i];
					if (i < m - 1)
						cout << ',';
					i++;
				}	

		}
}
