#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <int> a(n);

	set <int> s;

	for (int i = 0; i < n; i++)
		{
			s.insert(a[i]);
			cin >> a[i];
		}

	for (int i = 0; i < n; i++)
		{
			vector <int> q;

			q.reserve(s.size());

			for (set <int> :: iterator it = s.begin(); it != s.end(); it++)
				q.push_back(a[i] + *it);

			for (vector <int> :: iterator it = q.begin(); it != q.end(); it++)
				s.insert(*it);
		}


	set <int> iterator en = --s.end();

  	for (set <int> :: iterator it = s.begin(); it != s.end())
  		{
  	 		if (vec[i + 1] - vec[i] > 1)
  	 			{
  	 				cout << vec[i] + 1;
  	 				return 0;
  	 			}
  	 	}

  	 cout << vec[sz - 1] + 1;

  	 return 0;
}
