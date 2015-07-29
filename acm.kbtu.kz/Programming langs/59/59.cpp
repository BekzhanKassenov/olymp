#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <vector <int> > a(n, vector <int> (n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

   vector <int> d(n);

   vector <bool> used(n);

   queue <int> q;

   int z, b;
   cin >> z >> b;
   z--, b--;

   if (z == b)
   	{
   		cout << 0;
   		return 0;
   	}

   q.push(z);
   used[z] = 1;

   while (!q.empty())
   	{
   		int v = q.front();
   		q.pop();

   		for (int i = 0; i < n; i++)
   			{
   				if (a[v][i] && !used[i])
   					{
   						d[i] = d[v] + 1;
   						used[i] = 1;
   						q.push(i);
   					}
   			}
   	}
   if (d[b] == 0)
   	cout << -1;
   else
   	cout << d[b];
   return 0;	

}
