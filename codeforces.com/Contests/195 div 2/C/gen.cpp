#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	freopen("in", "w", stdout);
    vector <int> res;

    int st = rand() + 1;

    int gr = (rand() << 10) + rand();

    do {
    	res.push_back(st);
    	st += rand();
    } while (st < gr);

    cout << res.size() << endl;

    for (int i = 0; i < (int)res.size(); i++)
    	cout << res[i] << ' ';

    return 0;	
}
