#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a,b,r;
	cin >> a >> b >> r;
	if ((2*r)<=min(a,b))
		cout << "First";
	else
		cout << "Second";
	return 0;
}
