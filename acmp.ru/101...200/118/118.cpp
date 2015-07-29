#include <fstream>
int n,m;
int f(int z)
{
	if (z==1) return 1;
	else return (1+(f(z-1)+m-1) % z);
}

main()
{
	std:: ifstream i("input.txt");
	std:: ofstream o("output.txt");
	i>>n>>m;
	o<<f(n);
}
