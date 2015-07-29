#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

string team_name, surname[3];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    getline(cin, team_name);

    for (int i = 0; i < 3; i++)
        getline(cin, surname[i]);

    sort(surname, surname + 3);

    printf("%s: %s, %s, %s\n", team_name.c_str(), surname[0].c_str(),
                               surname[1].c_str(), surname[2].c_str());


    return 0;
}
