#include <fstream>
#include <algorithm>
#include <string>

main()
{
   std :: fstream i ("input.txt");
   std :: ofstream o("output.txt");

	std :: string s;

	i >> s;

	for (sort(s.begin(), s.end()); next_permutation(s.begin(), s.end());)
		o << s << '\n'; 
}
