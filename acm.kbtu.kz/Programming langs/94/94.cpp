#include <iostream>
#include <vector>

using namespace std;

#define INF 2000000000

int main()
{
	int n, s, f;
	cin >> n >> s >> f;
	vector <vector <int> > a(n, vector <int> (n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

  	vector <bool> used(n, 0);

  	vector <int> d(n, INF);

  	s--;
  	f--;
  	d[s] = 0;

  	for (int i = 0; i < n; i++)
  		{
  			int v = -1;
  			for (int j = 0; j < n; j++)
  				if ((v == -1 || d[j] < d[v]) && !used[j])
  					v = j;

  			used[v] = true;
  			for (int j = 0; j < n; j++)
  				if (a[v][j] > 0)
  					d[j] = min(d[j], d[v] + a[v][j]);
  		}
   if (d[f] < INF)
   	cout << d[f];
   else
   	cout << -1;

   return 0;
}
