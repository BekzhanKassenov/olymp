#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 2000000000

int main()
{
	int n;
	cin >> n;

   vector <vector <int> > g(n, vector <int> (n));

   vector <vector <pair <int, int> > > g(n, vector <pair <int, int> > (n));

   for (int i = 0; i < n; i++)
   	for (int j = 0; j < n; j++)
   		cin >> a[i][j];
   
   for (int i = 0; i < n; i++)
   	for (int j = 0; j < n; j++)
   		for (int k = 0; k < n; k++)
   			{
   				if (a[i][j] > a[i][k] + a[k][j]
}
