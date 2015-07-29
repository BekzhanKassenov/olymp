#include <fstream>

int main()
{
	std::ifstream i("input.txt");
	std::ofstream o("output.txt");
	char a,b;
	i>>a>>b;
	if ((a-'A'+1+b-'0')%2==0) o<<"BLACK";
	else o<<"WHITE";
	exit(0);
}
