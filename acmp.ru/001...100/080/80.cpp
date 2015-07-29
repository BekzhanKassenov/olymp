#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char s[101];

	scanf("%s", s);

	char s1[1000];

	bool flag = true;

	if (scanf("%s", s1) == 1)
		flag = false;

	int a, b;

	double c;

	char z, z1;

	if (sscanf(s, "%d%c%d%c%lf", &a, &z, &b, &z1, &c) != 5)
	    flag = false;
		
	if (z1 != '=')
		flag = false;

	bool flag1 = false;

	switch(z)
		{
			case '+':
				if (a + b == c)
					flag1 = true;
				break;
			
			case '-':
				if (a - b == c)
					flag1 = true;
				break;

			case '*':
				if (a * b == c)
					flag1 = true;
				break;

			case '/':
				if ((a + .0) / (b + .0) == c)
					flag1 = true;
				break;

			default: 
				flag = false;	
		}

   	if (!flag)
   		cout << "ERROR";
   	else
   		if (!flag1)
   			cout << "NO";
   		else
   			cout << "YES";

   	return 0;	
}
