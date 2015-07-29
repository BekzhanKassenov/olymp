#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;
	double p, ans;
	for (int i=0;i<n;i++)
		{
			cin >> p;
			ans +=p;
		}
	printf("%.5lf",ans/double(n));
	return 0;
}