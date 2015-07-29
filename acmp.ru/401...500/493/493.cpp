#include <fstream>
using namespace std;
main()
{
	ifstream i("input.txt");
	ofstream o("output.txt");
	int n,m;
	i>>n>>m;
	bool a[105][105];
	char c;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			{
				i>>c;
				if (c=='*')
					a[i][j]=true;
				else a[i][j]=false;
			}
	int z=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
				if ((!a[i][j]) && (!a[i-1][j]) && (!a[i][j-1]) && (!a[i][j+1]) && (!a[i+1][j]))
					z++;
	o<<z;
}
