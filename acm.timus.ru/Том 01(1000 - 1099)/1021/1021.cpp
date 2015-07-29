#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define abs(x) (x < 0) ? (-x) : x

int n;

vector <int> a;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif	

	int m;
	
	cin >> n;

	a.resize(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];
   
   cin >> m;
   
   vector <int> b(m);

   for (int i = 0; i < m; i++)
   	cin >> b[i];

   for (int i = 0; i < m; i++)
   	{
   		int k = 10000 - b[i];
   		if (binary_search(a.begin(), a.end(), k))
   			{
   				cout << "YES";
   				return 0;
   			}
   	}
   cout << "NO";
   return 0;
}
