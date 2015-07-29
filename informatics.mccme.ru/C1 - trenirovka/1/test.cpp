#include <iostream>
#include <cstdio>
#include <math.h>

int main()
{ 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	float x,y;

	std :: cin >> x >> y;
	
	if (y>=0 && x<= 1.57 && y<=sin(x) && x>=0)
		std :: cout << "YES";
	else
		std :: cout << "NO";

}
