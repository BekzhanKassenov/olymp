#include <iostream>
#include <cmath>

using namespace std;

long long sqr(long long n)
{
	return n*n;
}

bool test(long long n)
{
	long long z = 8*n+1;
	long long m = (long long)(sqrt(z));
	if (sqr(m)==z) return true;
	return false;
}

int main()
{
	long long n;
	cin >> n;
	for (long long i = 1;;i++)
		{
			long long j = n-(i*(i+1))/2;
			if (j<=0) break;
			if (test(j))
				{
					cout<<"YES";
					return 0;
				}
		}
	cout << "NO";
  	return 0;
}
