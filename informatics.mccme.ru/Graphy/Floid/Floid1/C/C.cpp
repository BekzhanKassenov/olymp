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
	vector <vector <int> > d(n, vector <int> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> d[i][j];
   
   for (int k = 0; k < n; k++)
   	for (int i = 0; i < n; i++)
   		for (int j = 0; j < n; j++)
   			d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
   for (int i = 0; i < n; i++)
   	if (d[i][i] < 0)
   		{
   			cout << "-1";
   			return 0;
   		}
   int ans = 2000000000;
   for (int i = 0; i < n; i++)
   	for (int j = 0; j < n; j++)
   		if (i != j)
   			ans = min(ans,d[i][j]);
   cout << ans;
   return 0;
}
