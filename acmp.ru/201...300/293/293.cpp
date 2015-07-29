#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i=0;i<n;i++)
		cin >> a[i];
	int pos;
	float ans = 0;
	for (int i=0;i<n;i++)
		{
			float k;
			cin >> k;
			k /= 100;
			k *= a[i];
			if (k > ans)
				{
					ans = k;
					pos = i;
				}
		}
	pos++;
	cout << pos;
	return 0;
}
