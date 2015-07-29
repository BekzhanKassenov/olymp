#include <iostream>

using namespace std;

int main()
{
	int n[4];
	int s[4];

	int ind = 0;

	for (int i = 0; i < 4; i++)
		cin >> s[i];     

	int kq = 0;

	for (int i = 1; i < 4; i++)
		{
			for (int j = i + 1; j < 4; j++)
				if (s[i] == s[j])
					{
						kq++;
						break;
					}
		} 
	cout << kq;
}
