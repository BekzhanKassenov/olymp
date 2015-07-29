#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "w", stdout);

	srand(time(NULL));

	int n = rand() % 5;

	cout << n << endl;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		a[i] = i;

	random_shuffle(a.begin(), a.end());

	for (int i = 0; i < n; i++)
		cout << a[i] + 1 << ' ';

	cout << endl;

	return 0;	
}
