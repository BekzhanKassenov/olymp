#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int count_of_inv(vector <string>& s, vector <string>& z)
{
	int n = s.size();
	int ans = 0;
	for (int i = 0; i < n; i++)
		{	
			int p, p1;
			for (int j = 0; j < n; j++)
				if (s[j] == z[i])
					{
						p = j;
						break;
				   }
		   for (int k = i + 1; k < n; k++)	
		   	{
		   		for (int j = 0; j < n; j++)
		   			if (s[j] == z[k])
		   				{
		   					p1 = j;
		   					break;
		   				}
		   		if (p1 < p)
		   			ans ++;
		   	}

		}
  return ans;
}

int poxozhest(vector <string>& s, vector <string>& a)
{
	vector <string> z = s;
	sort (z.begin(),z.end());
	int len = z.size();
	int f = a.size();
	int ans = 10;
	bool q = false;
	do 
	{
		int uk = 0;
		bool ok = false;
		for (int i = 0; i < f; i++)
			{
				if (a[i] == z[uk])
					{
						uk++;
						if (uk == len)
							{
								ok = true;
								break;
							}
					}
			}
		
		if (ok)
			{
				int x = count_of_inv(z,s);
				ans = min (ans, x);
				q = true;
			}
	}
	while (next_permutation(z.begin(), z.end()));
	if (q)
		{
			return (len * ( len - 1 ) ) / 2 - ans + 1;
		}
	else
		return 0;

}

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin >> n;
	vector <string> a(n);
	for (int i = 0; i < n ;i++)
		cin >> a[i];
	int m;
	cin >> m;
	vector <vector <string> > arxiv(m);
	int k;
	for (int i = 0 ; i < m; i++)
		{
			cin >> k;
			arxiv[i].resize(k);
			for (int j = 0; j < k; j++)
				cin >> arxiv[i][j];
		}
	int ans = 0;
	int nmb = -1;
	for (int i = 0; i < m; i++)
		{
			int p = poxozhest(a, arxiv[i]);
		   if (p != 0 && (ans < p))
		   	{
		   		nmb = i;
		   		ans = p;
		   	}
		}
	if (nmb == -1)
		 cout << "Brand new problem!" << endl;
	else
		{	
			cout << ++nmb << endl;
			cout << "[:";
			for (int i = 0; i < ans; i++)
				cout << "|";
			cout << ":]";
		}
	return 0;
}

