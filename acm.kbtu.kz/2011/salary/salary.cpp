#include <iostream>
#include <cstdio>
#include <sstream>

using namespace std;

int main()
{
long long n;
stringstream s;
stringstream sp;
string z;
cin>>n;
long long i=1;
long long sum=0;
long long kb;
do
{
  kb=i*i*i;
  sp<<kb;
  sp>>z;
  sum+=z.length();
  s<<z;
  cout<<z<<" "<<sum;
  if (sum>=n)
     {
	z="";
	s>>z;
	cout<<z[n-1];
	return 0;
     }
  i++;
}
while (false);
return 0;
}
