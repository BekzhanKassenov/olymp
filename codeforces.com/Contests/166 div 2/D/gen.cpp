#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	freopen("in", "w", stdout);

	srand(time(NULL));

	int n = rand() % 500;

	for (int i = 0; i < n; i++)
		cout << char(rand() % 26 + 'a');

	cout << endl;

	for (int i = 0; i < 26; i++)
		cout << rand() % 2;

	cout << endl;

	cout << rand() % n;	

    return 0;
}
