#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long long s = 0;

vector <vector <int> > a;

int clc(int n, int k)
{
    if (n < 0) return 0;
    if (a[n][k] == -1)
    	a[n][k] = 0;
    if (n == 0) 
    	{
    		a[n][k] = 1;
  			return 1;
    	}
    for (int i = k + 1; i <= n; i++)
        {
        		if (a[n - i][i] == -1)
        			{
        				clc(n - i, i);
        				a[n][k] += a[n - i][i];
        		   }
        		else
        			a[n][k] += a[n - i][i];
        }
    return a[n][k];
}

int main()
{
    int n;
    cin >> n;
    a.assign(n + 10, vector <int> (n + 10, -1));
    cout << clc(n, 0);
    return 0;
}