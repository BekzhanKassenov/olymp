#include <fstream>

main()
{
	std :: ifstream i("input.txt");
	std :: ofstream o("output.txt");

	double r, R, h, b;

	i >> R >> r >> h >> b;

	h = r - b + h;

	if (r * r + h * h <= R * R) 
		o << "YES";
	else
		o << "NO";
}
