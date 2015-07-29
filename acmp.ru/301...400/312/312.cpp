#include <fstream>
main()
{
	std::ifstream i("input.txt");
	std::ofstream o("output.txt");
	int a,b,n;
	i>>a>>b>>n;
	o<<(a+(n-1)*(b-a));
}
