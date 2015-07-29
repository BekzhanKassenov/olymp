#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.length();
	vector <int> a(n), b(n);
	int ch = 0, nch = 0;	
	if (s[0] == '1')
		{
			b[0] = 1;
			nch = 1;
		}
	for (int i = 1; i < n; i++)
		{
			if (s[i] == '1')
				{
					if (((i + 1) & 1) == 1)
						{
							nch ++;
							b[i] = b[i - 1] + 1;
							a[i] = a[i - 1];
						}
					else
						{
							ch ++;
							b[i] = b[i - 1];
							a[i] = a[i - 1] + 1;
						}
				}
			else
				{
					a[i] = a[i - 1];
					b[i] = b[i - 1];
				}
	   }	
	/*for (int i = 0; i < n; i++)
		{
			cout << a[i] << ' ';
		}
	cout << endl;
	for (int i = 0; i < n; i++)
		{
			cout << b[i] << ' ';
		}
	cout << endl;
	cout << "CH : " << ch << endl;
	cout << "NCH : " << nch << endl; */
   for (int i = 0; i < n; i++)
   	{
   		if (s[i] == '0')
   			{	
   				if (a[i] + nch - b[i] == b[i] + ch - a[i])
   					{
   						cout << i + 1;
   						return 0;
   					} 
   			}
   		else
   			{
   				if (((i + 1) & 1) == 1)
   					{
   						if (b[i] - 1 + ch - a[i] == a[i] + nch - b[i])
   							{
   								cout << i + 1;
   								return 0;
   							}
   					}
   				else
   					{
   						if (a[i] - 1 + nch - b[i] == b[i] + ch - a[i])
   							{
   								cout << i + 1;
   								return 0;
   							}
   					}
   			}
   	}
    cout << 0;
	return 0;
}

