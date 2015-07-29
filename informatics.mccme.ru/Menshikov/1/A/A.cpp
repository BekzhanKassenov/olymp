#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
	if (n == 1)
		return false;
	int k = sqrt(n);
	for (int i = 2; i <=k; i++)
		if (n % i == 0)
			return false;
   return true;
}

int main()
{
	int n,m;
	cin >> n >> m;
	bool is = false;
	for (int i = n; i <= m; i++)
		if (is_prime(i))
			{
				cout << i << endl;
				is = true;
			}
   if (!is)
   	cout << "Absent";
	return 0;
}
