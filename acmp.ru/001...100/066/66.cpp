#include <fstream>

main()
{
	char a[27] = "snvfrghjoklzqmpawtdyibecux", b;

	std :: ifstream i("input.txt");
	
	i >> b;

	std :: ofstream o("output.txt"); 
	o << a[b - 'a'];
}
