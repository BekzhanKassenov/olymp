#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

pair <string, int> a[3];

int main()
{
	a[0].first = "Emperor Penguin";

	a[1].first = "Little Penguin";

	a[2].first = "Macaroni Penguin";

	string s;

	int n;

	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n;

	getline(cin, s);

	for (int i = 0; i < n; i++)
		{
			getline(cin , s);
			for (int j = 0; j < 3; j++)
				if (a[j].first == s)
					a[j].second++;
		}

	int a0 = a[0].second;
	int a1 = a[1].second;
	int a2 = a[2].second;

	if (a0 > a1 && a0 > a2)
		{
			cout << a[0].first << endl;
			return 0;
		}

	if (a1 > a0 && a1 > a2)
		{
			cout << a[1].first << endl;
			return 0;
		}

	cout << a[2].first << endl;
	return 0;
}
