#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int f,f1 = 0, f2 = 1;
	vector <int> a;
	a.push_back(0);
	a.push_back(1);
	int i = 2;

	if (n==0)
		{
			cout << "0 0 0";
			goto END;
		}
	if (n==1)
		{
			cout << "0 0 1";
 			goto END;
		}
	if (n==2)
		{	
			cout << "0 1 1 ";
			goto END;
		}

	while (f!=n)
		{
			f = f1+f2;
			f1 = f2;
			f2 = f;
			a.push_back(f);
			i++;
		}
	cout << a[i-5] << ' ' << a[i-4] << ' ' << a[i-2];
	END: return 0;

}
