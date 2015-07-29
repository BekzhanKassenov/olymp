#include <fstream>

#define g a[i * n + j]

#define z for (i = 0; i < n; i++) for (j = 0; j < m; j++)

char a[11000];

int i, j, x, f, n, m;

main()
{
	std :: ifstream u ("input.txt");

	u >> n >> m;

	z
		u >> g;

	z		
		u >> x, f |= !(g == 46 || g == 82 && x > 3 || g == 71 && x % 4 > 1 || g == 66 && x % 2);

	std :: ofstream o ("output.txt"); 
	o << (f ? "NO" : "YES");
}
