#include <fstream>
main()
{
	std::ifstream i("input.txt");
	std::ofstream o("output.txt");
	int a,b;
	i>>a>>b;
	if (a<b) o<<'<';
	if (a>b) o<<'>';
	if (a==b) o<<'=';
}

