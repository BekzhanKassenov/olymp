#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool is(int a)
{
	if (a == 1 || a == 0)
		return true;
	return false;
}

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
   cout << a[0];
   int i = 1;
   while (i < n)
   	{
   		if (a[i] == 0)
   			{
   				cout << '+' << a[i];
   				i++;
   				if (i < n)
   					cout << '+' << a[i];
   				i ++;
   			}
   		else
   			if (a[i] == 1 && ((i < n - 1 && is(a[i + 1])) || (i == n - 1)))
   				{
   					cout << '+' << a[i];
   					i++;
   			   }
   			else
   				if (!is(a[i]) && is(a[i - 1]) && i > 1 && is(a[i - 2]))
   					{
   						cout << '+' << a[i];
   					 	i++;	
   					}
   				else
   					{
   						cout << '*' << a[i];
   				      i++;
   				   }
   	}
   return 0;
}
