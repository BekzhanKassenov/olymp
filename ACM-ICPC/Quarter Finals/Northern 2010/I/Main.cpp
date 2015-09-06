/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "ideal"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

vector <string> split(const string& str) {
    int len = str.length();
    vector <string > res;
    string tmp;

    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            if (!tmp.empty()) {
                res.push_back(tmp);
                tmp.clear();
            }
        } else {
            tmp.append(1, str[i]);
        }
    }
    if (!tmp.empty()) {
        res.push_back(tmp);
    }

    return res;
}

bool splitter(const string& str) {
    for (char c: str) {
        if (c != '-') {
            return false;
        }
    }

    return true;
}

int strToInt(const string& s) {
    int res = 0;
    for (size_t i = 0; i < s.size(); i++) {
        res *= 10;
        res += s[i] - '0';
    }

    return res;
}

bool solved[310][30];
int num[310];
int place[310];
double instab[30];

vector <string> input;
string temp;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    while (getline(cin, temp)) {
        input.emplace_back(temp);
    }

    int pos = input.size() - 1;

    while (pos >= 0) {
        if (splitter(input[pos])) {
            break;
        }

        pos--;
    }

    int problems = split(input[pos - 1]).size() - 4;
    int teams = input.size() - pos - 1;

    for (size_t i = pos + 1; i < input.size(); i++) {
        vector <string> line = split(input[i]);
        place[i - pos] = strToInt(line.back());

        for (int j = 0; j < 3; j++) {
            line.pop_back();
        }

        for (int j = problems - 1; j >= 0; j--) {
            if (line.back()[0] == '+') {
                solved[i - pos][j] = true;
                num[i - pos]++;
            } else {
                solved[i - pos][j] = false;
            }

            line.pop_back();
        }
    }
    
    double vainnes = 0;
    for (int i = 1; i <= teams; i++) {
        bool solve = false;

        for (int j = 0; j < problems; j++) {
            solve |= solved[i][j];
        }

        if (!solve) {
            vainnes += 1 / (teams + .0);
        }
    }

    double oversim = 0;
    for (int i = 1; i <= teams; i++) {
        if (num[i] == problems) {
            oversim += 1 / (teams + .0);
        }
    }

    double evennes = 0;
    for (int i = 1; i < teams; i++) {
        if (num[i] - num[i + 1] > 1) {
            evennes += (num[i] - num[i + 1] - 1) / (problems + .0);
        }
    }

    double unsolve = 0;
    for (int j = 0; j < problems; j++) {
        bool solve = false;
        for (int i = 1; i <= teams; i++) {
            solve |= solved[i][j];
        }

        if (!solve) {
            unsolve += 1 / (problems + .0);
        }
    }

    double mean = 0;
    for (int j = 0; j < problems; j++) {
        int lowest = 0;

        for (int i = 1; i <= teams; i++) {
            if (solved[i][j]) {
                lowest = max(lowest, place[i]);
            }
        }

        for (int i = 1; i <= teams; i++) {
            if (place[i] < lowest && !solved[i][j]) {
                instab[j] += 1 / (teams + .0);
            }
        }
        
        mean += instab[j];
    }

    mean /= (problems + .0);

    double negidealness = 1.03 * vainnes + 3.141 * oversim + 2.171 * evennes + 1.414 * unsolve + mean;

    cout.precision(3);
    cout << fixed;

    cout << "Vainness = " << vainnes << endl;
    cout << "Oversimplification = " << oversim << endl;
    cout << "Evenness = " << evennes << endl;
    cout << "Unsolvability = " << unsolve << endl;
    
    for (int j = 0; j < problems; j++) {
        cout << "Instability " << j + 1 << " = " << instab[j] << endl;
    }
    
    cout << "Negidealness = " << negidealness << endl;

    return 0;
}
