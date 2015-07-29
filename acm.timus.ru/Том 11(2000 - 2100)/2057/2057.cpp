#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 200010;

char s[MAXN];
vector <pair <char, int> > vec;
bool new_group = true;
int ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);

    for (int i = 0; s[i]; i++) {
        if (vec.empty() || vec.back().first != s[i]) {
            vec.push_back(make_pair(s[i], 1));
        } else {
            vec.back().second++;
        }
    }

    for (size_t i = 0; i < vec.size(); i++) {
        if (
    }
    
    return 0;
}
