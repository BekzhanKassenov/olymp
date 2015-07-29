#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define F first
#define S second

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

  	cin >> n;
  	
  	vector <pair <int, int> > a(n);

  	for (int i = 0; i < n; i++)
  		{
  			cin >> a[i].F;
  			a[i].S = 1;
  		}

  	for (int q = 0; q < 2; q++)
  		{
  			int k;

  			cin >> k;

  			for (int i = 0; i < k; i++)
  				{
  					int tmp;

  					cin >> tmp;

  					for (int i = 0; i < n; i++)
  						if (a[i].F == tmp)
  							a[i].S ++;
  				}
  		}

  	int ans = 0;
  	
  	for (int i = 0; i < n; i++)
  		if (a[i].S == 3)
  			ans++;

  	cout << ans;

  	return 0;
}
