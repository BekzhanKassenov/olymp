#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
 	#ifndef ONLINE_JUDGE
 		freopen("in", "r", stdin);
 	#endif

 	char c;

 	int x, y, x1, y1;

 	cin >> c;

 	x = c - 'a' + 1;

 	cin >> c;

 	y = c - '0';

 	cin >> c;

 	x1 = c - 'a' + 1;

 	cin >> c;

 	y1 = c - '0';

 	if (y1 == 7)
 		{
 			if (y == 7 && (x == 1 && x1 == 2 || x == 8 && x1 == 7))
 				cout << "DRAW";
 			else
 				{
 					if (
 				}
 		}
 	else
 		{
 			cout << "WHITE";
 		}	

}
