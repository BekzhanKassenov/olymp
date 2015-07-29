#include <fstream>
#include <string>
using namespace std;
bool t(string z)
{
	int s=0,m=0;
	s=z[0]+z[1]+z[2]-144;
	m=z[5]+z[4]+z[3]-144;
	if ((s>m && z[5]==57) || (m>s && z[5]==48))
		return false;
	return true;
}
main()
{	
	ifstream i("input.txt");
	ofstream o("output.txt");
	int n,j;
	i>>n;
	for (j=0;j<n;j++)
		{
			string z;
			i>>z;
			if (t(z))
				o<<"Yes\n";
			else
				o<<"No\n";
		}
}
