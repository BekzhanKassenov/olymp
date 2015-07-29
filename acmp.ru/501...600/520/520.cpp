#include <iostream> 
#include <cstdio>

using namespace std;

int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

   	int n;

   	cin >> n;

   	int a = 0, b = 0;

	while(n > 133) 
		{
			n -= 144;
			a++; 
		}
	while(n > 9) 
		{
			n -= 12; 
			b++;
		} 

	cout << a << ' ' << b << ' ' << (n > 0 ? n : 0);

	return 0;	
}