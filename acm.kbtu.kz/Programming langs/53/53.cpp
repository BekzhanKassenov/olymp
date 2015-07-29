#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	while (cin >> n)
		ans += n;
	cout << ans / 2;
}
