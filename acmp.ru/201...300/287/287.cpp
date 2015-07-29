#include <fstream>
#include <string>
#include <set>

using namespace std;

int j;

main()
{
	ifstream i("input.txt");
	ofstream o("output.txt");
	int n,m;
	i >> n >> m;
	string s;
	i >> s;
	set <string> q;
	for (; j <= n - m; j++)
		q.insert(s.substr(j,m));
	o << q.size() << endl;
}
