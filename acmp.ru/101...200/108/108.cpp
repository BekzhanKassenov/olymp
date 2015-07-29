#include <fstream>
int main()
{
	std::ifstream a("input.txt");
	std::ofstream b("output.txt");
	int n;
	a>>n;
	b<<n;
	return 0;
}
