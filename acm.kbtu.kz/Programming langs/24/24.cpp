#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	vector <int> a;

	int x;
	while (cin >> x && x != 0)
		a.push_back(x);
	cout << a.size() << endl;
	for (int i = 0; i < (int)a.size(); i++)
		cout << a[i] << ' ';
	return 0;
}
