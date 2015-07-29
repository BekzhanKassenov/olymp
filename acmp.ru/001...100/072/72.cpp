#include <fstream>
#include <string>
using namespace std;
main()
{
	ifstream i("input.txt");
	ofstream o("output.txt");
	string s;
	i>>s;
	next_permutation(s.begin(),s.end());
	o<<s;
}
