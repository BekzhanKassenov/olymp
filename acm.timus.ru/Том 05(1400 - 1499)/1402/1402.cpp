#include <iostream>
#include <cstdio>

using namespace std;

unsigned long long a[22];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
   	#endif

   	int n;

   	cin >> n;

   	if (n == 21) 
   		{
   			cout << "138879579704209680000";
   			return 0;
   		}

   	a[1] = 0;

   	for (int i = 2; i <= n; i++)
   		{
   			a[i] = a[i - 1] * i + (i - 1) * i;
   		}

   	cout << a[n];	

   	return 0;
}
