#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int nmb(char a)
{	
	switch (a)
		{
			case '1': return 1;
			case '2': return 2;   
			case '3': return 3;
			case '4': return 4;
			case '5': return 5;
			case '6': return 6;
			case '7': return 7;
			case '8': return 8;
			case '9': return 9;
			case '0': return 0;
			case 'A': return 10;
			case 'B': return 11;
			case 'C': return 12;
			case 'D': return 13;
			case 'E': return 14;
			case 'F': return 15;
			case 'G': return 16;
			case 'H': return 17;
			case 'I': return 18;
			case 'J': return 19;
			case 'K': return 20;
			case 'L': return 21;
			case 'M': return 22;
			case 'N': return 23;
			case 'O': return 24;
			case 'P': return 25;
			case 'Q': return 26;
		}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	cin>>s;
	for (int i=1;i<=s.length();i++)	
		{	
			int k=nmb(s[i-1]);
			k-=i;
			while (k<0) k+=27;
			if (k==0)
				{
					cout<<' ';
					continue;
				}
			cout<<char(k+'a'-1);
		}
	return 0;
}
