#include <fstream>

int d[5000000], k, p, i = 2;

main() {
	std :: ifstream ("input.txt") >> k >> p;

   	for (d[2] = 1 % p; i < k; i++)
   		d[i + 1] = (d[i] + i % 2 * d[i / 2 + 1]) % p; 

   	std :: ofstream ("output.txt") << d[k];
}