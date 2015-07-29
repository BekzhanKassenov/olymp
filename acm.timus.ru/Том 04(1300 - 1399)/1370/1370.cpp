#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
  	#endif

  	int n, m;

  	cin >> n >> m;

  	vector <int> a(n);
  	
  	for (int i = 0; i < n; i++)
  		cin >> a[i];

  	for (int i = m; i < m + 10; i++)
  		{
  			cout << a[i % n];
  		}
  	
  	return 0;
}
