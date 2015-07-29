#include <iostream>
#include <cstdio>

using namespace std;

bool test(int n)
{
	int c=n;
	int k=0,i=0;
	while (c>0)
		{
			i++;
			k+=c % 10;
			c /= 10;
		}
	if (k%i==0)
		return true;
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	bool solved = false;
	int i = 1;
	while (!solved)
		{
			if (test(i))
				n--;
			if (n==0)
				{
					solved = true;
					cout << i;
				}
			i++;
		}
	return 0;
}
