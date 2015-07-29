#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> d(1000);
	d[0] = 1;
	for (int i = 1; i <=3; i++)
		for (int j = 0; j < i; j++)
			d[i] += d[j];

	for (int i = 4; i <=n; i++)
		for (int j = i - 3; j < i; j++)
			d[i] += d[j];
	cout << d[n];
}

