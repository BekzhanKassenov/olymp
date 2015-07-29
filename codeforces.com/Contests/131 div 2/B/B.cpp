#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int d[10];

bool check(int mod)
{
	for (int i = 1; i < 9; i++)
		if (i % 3 == mod && d[i] > 0)
			{
				d[i]--;
				return true;
			}
	mod = 3 - mod;
	bool p1 = false;
	for (int i = 1; i < 9; i++)
		{
			if (i % 3 == mod && d[i])
				{
					d[i] --;
					p1 = true;
					break;
			 	}	
		}
	if (!p1)
		return false;
	else
		p1 = false;
	for (int i = 1; i < 9; i++)
		{
			if (i % 3 == mod && d[i])
				{
					d[i] --;
					p1 = true;
					break;
			 	}	
		}
	if (!p1)
		return false;
	else
		return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
	#endif
	int n;
	cin >> n;
	int v;
	int sum = 0;
	for (int i = 0; i < n; i++)
		{
			cin >> v;
			d[v] ++;
			sum += v;
		}
	if (d[0] == 0)
		{
			cout << -1;
			return 0;
		}
	if (sum % 3 != 0)
		if (!check(sum % 3))
			{
				cout << -1;
				return 0;
			}
	/*for (int i = 0; i < 10; i++)
		cout << i << " : " << d[i] << endl;*/
	bool k = false;
	for (int i = 1; i < 10; i++)
		if (d[i] > 0)
			k = true;
   if (!k)	
   	cout << 0;
   else
   	{
   		for (int i = 9; i >= 0; i--)
   			for (;d[i]--; )
   				cout << i;
   	}
}
