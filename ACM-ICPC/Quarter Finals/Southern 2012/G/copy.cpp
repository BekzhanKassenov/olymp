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
const int BASE = 38;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;

entry p[MAXN * 4];
int pSize = 0;

vector <int> Map[4 * MAXN];

vector <entry> database[MAXN];

long long _hash(const string& str) {
    long long result = 0;
    for (char c: str) {
        result *= BASE;

        if (isalpha(c)) {
            result += c - 'a';
        } else {
            result += (c - '0') + 26;
        }                   
    }

    return result;
}

void parseLine(vector <entry>& result) {
    result.clear();
    
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        string temp;
        cin >> temp;
        result.push_back(_hash(temp));
    }

    sort(all(result));
}

bool cmp(int a, int b) {
    return Map[a].size() < Map[b].size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        parseLine(database[i]);

        for (auto& en: database[i]) {
            p[pSize++] = en;
        }
    }

    sort(p, p + pSize);
    pSize = unique(p, p + pSize) - p;

    for (int i = 0; i < n; i++) {
        for (auto& en: database[i]) {
            int pos = lower_bound(p, p + pSize, en) - p;
            assert(pos < pSize && p[pos] == en);

            Map[pos].push_back(i);
        }
    }

    cin >> m;
    vector <entry> query;
    bool result;

    for (int i = 0; i < m; i++) {
        parseLine(query);

        result = true;
        vector <int> vec;
        for (auto& en: query) {
            int pos = lower_bound(p, p + pSize, en) - p;
            
            if (pos == pSize || p[pos] != en) {
                result = false;
                break;
            }
            
            vec.push_back(pos);
        }

        if (!result) {
            cout << 0 << endl;
            continue;
        }

        sort(all(vec), cmp);
        int result = 0;
        
        for (int ptr: Map[vec[0]]) {
            bool ok = true;
            for (size_t i = 1; i < vec.size(); i++) {
                if (!binary_search(all(Map[vec[i]]), ptr)) {
                    ok = false;
                }
            }

            result += ok;
        }

        cout << result << endl;

    }

    return 0;
}
