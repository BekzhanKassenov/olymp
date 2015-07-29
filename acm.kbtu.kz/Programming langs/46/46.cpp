#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <vector <int> > a(30, vector <int> (30));

	a[0][0] = a[1][0] = a[1][1] = 1;

	for (int i = 2; i < 30; i++)
		{
			a[i][0] = 1;
			for (int j = 1; j < i; j++)
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			a[i][i] = 1;
		}
	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
				cout << a[i][j] << ' ';
			cout << endl;
		}
	return 0;
}
