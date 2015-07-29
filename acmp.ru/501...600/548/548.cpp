#include <fstream>
#include <string>

std :: string s, t, d[300][300];

int i, j, a, b;

main() {
	std :: ifstream r("input.txt");

	for (r >> s >> t, i = 1, a = s.size(), b = t.size(); i <= a; i++)
		d[i][0] = s.substr(0, i);

	for (j = 1; j <= b; j++)
		d[0][j] = t.substr(0, j);

	for (i = 1; i <= a; i++) 
		for (j = 1; j <= b; j++)
			d[i][j] = min(d[i - 1][j] + s[i - 1], d[i][j - 1] + t[j - 1]);	

	std :: ofstream("output.txt") << d[a][b];
}
