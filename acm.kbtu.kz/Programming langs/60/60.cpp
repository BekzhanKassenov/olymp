#include <iostream>
#include <vector>
#include <cstdio>
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

   vector <int> p(n, -1);
   
   int z, b;
   cin >> z >> b;
   z--, b--;

   if (z == b)
   	{
   		cout << 0 << endl << z + 1;
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
   						p[i] = v;
   						used[i] = 1;
   						q.push(i);
   					}
   			}
   	}

   if (d[b] == 0)
   	cout << -1;
   else
   	{
   		cout << d[b] << endl;
   		vector <int> ans;
   		for (int i = b; i != -1; i = p[i])
   			ans.push_back(i);
   		for (int i = ans.size() - 1; i >= 0; i--)
   			cout << ans[i] + 1 << ' ';
   	}
   return 0;	

}
