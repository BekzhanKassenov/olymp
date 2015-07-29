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
	int sumb = 0, summ = 0, lenb = 0, lenm = 0;
	for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] > 0)
				{
					sumb +=a[i];
					lenb++;
				}
			if (a[i] < 0)
				{
					summ -= a[i];
					lenm++;
				}	
		}
	if (sumb > summ)
		{
			cout << lenb << endl;
			for (int i = 0; i < n; i++)
				if (a[i] > 0)
					cout << i + 1 << ' ';
		}
	else
		{
			cout << lenm << endl;
			for (int i = 0; i < n; i++)
				if (a[i] < 0)
					cout << i + 1 << ' ';
		}
	return 0;
}
