#include <fstream>
int n,m,x;
main()
{
	std::ifstream a("input.txt");
	
	for (a >> n; a >> x; m += x);

	std::ofstream ("output.txt")<<std::min(m,n-m);
}
