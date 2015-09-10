/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 50010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
vector <string> database[MAXN];
vector <string> query;

map <vector <string>, int> Map;

void parseLine(vector <string>& result) {
    result.clear();
    
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        string temp;
        cin >> temp;
        result.push_back(temp);
    }

    sort(all(result));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        parseLine(database[i]);

        for (int mask = 0; mask < (1 << database[i].size()); mask++) {
            vector <string> vec;
            for (size_t j = 0; j < database[i].size(); j++) {
                if (mask & (1 << j)) {
                    vec.push_back(database[i][j]);
                }
            }

            Map[vec]++;
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        parseLine(query);

        if (Map.count(query)) {
            cout << Map[query] << endl;
        } else {
            cout << 0 << endl;
        }   
    }

    return 0;
}
