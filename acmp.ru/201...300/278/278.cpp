#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string a,b;
int lena,lenb;

int find_char(char c, int p)
{
	for (int i = p ; i < lenb ; i++)
		if (b[i] == c) return i;
	return -1;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin >> a >> b;

	lena=a.length();
	lenb=b.length();

	int k=-1;
	bool lg=false;

	for (int i = 0;i < lena;i++)
		{
			k = find_char( a[i] , k + 1 );
			if (k == -1) 
				{
					lg = true;
					break;
				}
		}
	if ( !lg )
		cout << "YES";
	else cout << "NO";
	return 0;
}

