#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
int a[100];
int cost[100];
int n;
cin>>n;
for (int i=0;i<n;i++)
cin>>a[i];
cost[0]=a[0];
cost[1]=a[1];
for (int i=2;i<n;i++)
cost[i]=min(cost[i-1],cost[i-2])+a[i];
cout<<cost[n-1];
return 0;
}
