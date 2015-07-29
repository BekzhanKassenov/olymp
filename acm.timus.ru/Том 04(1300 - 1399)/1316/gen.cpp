#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <set>

using namespace std;

int main()
{
	freopen("in", "w", stdout);

	srand(time(NULL));

	int n = rand() % 10000;

	multiset <int> s;

	for (int i = 0; i < n; i++)
		{
			int c = rand() % 3;

			if (c == 0)
				{
					cout << "BID ";

					int x = rand() % 1000000;

					cout << (double(x)) * 0.01 << endl;

					s.insert(x);
				}

			if (c == 1)
				{
					cout << "SALE ";

					int x = rand() % 1000000;

					cout << double(x) * 0.01 << ' ' << rand() % 10000 << endl;
				}

			if (c == 2)
				{
					if (s.empty())
						{
							i--;
							continue;
						}

					cout << "DEL ";

					int c = rand() % s.size();

					multiset <int> :: iterator it = s.begin();

					while (c--)
						it++;

					cout << (double(*it)) * 0.01 << endl;

					s.erase(it);
				}
		}

	cout << "QUIT" << endl;
}
	
