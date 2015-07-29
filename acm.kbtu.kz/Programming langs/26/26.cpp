#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int z = a[0], b = a[1], c = a[2], mx = a[0] * a[1] * a[2];
	for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
				for (int k = j + 1; k < n; k++)
					if (a[i] * a[j] * a[k] > mx)
						{
							mx = a[i] * a[j] * a[k];
							z = a[i];
							b = a[j];
							c = a[k];
						}
		}
	cout << z << ' ' << b << ' ' << c;
	return 0;
}
