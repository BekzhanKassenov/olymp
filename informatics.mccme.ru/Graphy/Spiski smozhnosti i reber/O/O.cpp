#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	vector <vector <int> > g(n, vector <int> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];
	vector <int> a, b;
	for (int i = 0; i < n; i++)
		{
			bool f1 = true, f2 = true;
			for (int j = 0; j < n; j++)
				{
					if (g[i][j])
						f1 = false;
					if (g[j][i])
						f2 = false;
				}
			if (f1)
				a.push_back(i + 1);
			if (f2)
				b.push_back(i + 1);
		}
	
  	cout << b.size() << ' ';
  	for (int i = 0; i < b.size(); i++)
  		cout << b[i] << ' ';
  	cout << endl;

  	cout << a.size() << ' ';
   for (int i = 0; i < a.size(); i++)
   	cout << a[i] << ' ';
  	return 0;
}
