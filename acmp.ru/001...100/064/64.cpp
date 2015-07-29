#include <fstream>
#include <string>
#include <cmath>

using namespace std;

string str(int n)
{
	string a,c;
	while (n>0)
	{
		a+=(n%10)+'0';
		n/=10;
	}
	for (int i=a.length()-1;i>=0;i--)
		c+=a[i];
	return c;
}

bool prost (int n)
{
	int k=int(sqrt(double(n)));
	for (int i=2;i<=k;i++)
		if ((n%i)==0) return false;
	return true;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int m;
	fin>>m;
	string s;
	int n=2;
	while (s.length()<10000)
		{
			while (!prost(n))
				n++;
			s+=str(n);
			n++;
		}
	for (int i=0;i<m;i++)
		{
			fin>>n;
			fout<<s[n-1];
		}
	return 0;
}
