#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int INF = 2000000000;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	vector <vector <int> > d(n, vector <int> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> d[i][j];
            if (d[i][j] == 100000) {
                d[i][j] = INF;
            }
        }

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (d[i][k] != INF && d[k][j] != INF)
					d[i][j] = max(min(d[i][j], d[i][k] + d[k][j]), -1000000000);

	for (int i = 0; i < n; i++)
		if (d[i][i] < 0)
			{
				cout << "YES";
				return 0;
			}
   cout << "NO";
   return 0;
}
