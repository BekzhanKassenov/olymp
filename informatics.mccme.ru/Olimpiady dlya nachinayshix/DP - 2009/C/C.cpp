#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
   vector <int> a;
   int n;
   while (cin >> n)
   	a.push_back(n);
   int ans = 0;
   n = 0;
   int len = a.size();
   for (int i = 0; i < len; i++)
   	{
   		if (i < len - 1 && a[i] == 2 && a[i + 1] != 2)
   			continue;
   		n++;
   		ans += a[i];
   	}
   cout << ans / n;
   return 0;
}
