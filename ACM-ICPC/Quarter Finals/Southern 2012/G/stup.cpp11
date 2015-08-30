/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define key first
#define val second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef int key;
typedef int val;
typedef long long entry;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 50010;
const int BASE = 26 + 11;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
vector <string> database[MAXN];

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

bool contains(const vector <string>& a, const vector <string>& b) {
    for (const string& str: b) {
        if (find(all(a), str) == a.end()) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        parseLine(database[i]);
    }

    cin >> m;
    vector <string> query;

    for (int i = 0; i < m; i++) {
        parseLine(query);

        int ans = 0;
        for (int j = 0; j < n; j++) {
            ans += contains(database[j], query);
        }
    
        cout << ans << endl;
    }

    return 0;
}
