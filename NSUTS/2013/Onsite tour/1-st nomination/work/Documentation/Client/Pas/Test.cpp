#include "Client\SolutionAdapter.h"
#include <iostream>

const WorldData *pWorld;
int playerIndex = 10;
int main() {
	std::pair<std::string, std::string> res = Program(1);
	std::cout << res.first << " " << res.second << std::endl;
	std::map<int, int> tmp = Strategy();
	std::cout << tmp.size() << " " << tmp.begin()->first << " " <<  tmp.begin()->second << std::endl;
	return 0;
}
