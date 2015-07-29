#include <iostream>

using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int k = c*(a-b);
	int t;
	if (k%b==0)
		t = k/b;
	else 
		t = k/b + 1;
	cout << t;
	return 0;
}
