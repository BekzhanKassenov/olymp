#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int a[5];
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && a[3] == a[4])
		cout << "Impossible";
	else
		{
			sort(a, a + 5);
			if (a[2] == a[3] && a[1] == a[2] && (a[1] == a[0] || a[3] == a[4]))
				cout << "Four of a Kind";
			else
				{
					if ((a[0] == a[1] && a[1] == a[2] && a[4] == a[3]) || (a[0] == a[1] && a[2] == a[3] && a[3] == a[4]))
						cout << "Full House";
					else
						if ( a[4] - a[3] == a[3] - a[2] && a[3] - a[2] == a[2] - a[1] && a[1] - a[0] == a[2] - a[1] && a[1] - a[0] == 1)
							cout << "Straight";
						else	
							{
								if ((a[0] == a[1] && a[1] == a[2]) || (a[1] == a[2] && a[2] == a[3]) || (a[2] == a[3] && a[3] == a[4]))
									cout << "Three of a Kind";
								else
									{
										if ((a[0] == a[1] && (a[2] == a[3] || a[3] == a[4])) || (a[3] == a[4] && a[1] == a[2]))
											cout << "Two Pairs";
										else
											{
												if (a[0] == a[1] || a[1] == a[2] || a[2] == a[3] || a[3] == a[4])
													cout << "One Pair";
												else
													cout << "Nothing";
											}
									}
							}
				}
		}
	return 0;
}
