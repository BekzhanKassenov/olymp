#include <fstream>
main()
{
	int a,b,c;
	std::ifstream i("input.txt");
	std::ofstream o("output.txt");
	i>>a>>b>>c;
	o<<2*a*b*c;
}
