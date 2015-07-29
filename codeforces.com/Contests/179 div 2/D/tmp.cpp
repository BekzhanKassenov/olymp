#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main() {
	freopen("in", "r", stdin);

	int n;

	cin >> n;

	set <int> s;

	vector <vector <int> > a(n, vector <int> (n));

	vector <int> x(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
		 	cin >> a[i][j];
		 	s.insert(a[i][j]);	
		}

	for (int i = 0; i < n; i++)
		{cin >> x[i];  cout << x[i] << ' ';}

   	int num = 0;

	for (set <int> :: iterator it = s.begin(); it != s.end(); it++) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (a[i][j] == (*it))	
					a[i][j] = num;

		num++;
	}

	fclose(stdin);
	freopen("in", "w", stdout);
	cout << n << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}

	for (int i = 0; i < n; i++)
		cout << x[i] << ' ';

	return 0;
}