/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstring>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "java"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n;
map <string, vector <int> > Map;
map <string, pair <string, int> > Map1;

inline bool is_letter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

inline void read_args(char s[], int& pos, vector <int>& vec) {
    vec.clear();

    while (!isdigit(s[pos]))
        pos++;

    int len = strlen(s);

    int num = 0;

    while (pos < len) {
        if (!isdigit(s[pos]) && num) {
            vec.push_back(num);
            num = 0;
        } else {
            num *= 10;
            num += s[pos] - '0';
        }

        pos++;
    }

    /*for (size_t i = 0; i < vec.size(); i++)
        cerr << vec[i] << ' ';

    cerr << endl;*/ 
}

inline void create_new_list(char s[]) {
    int pos = 4;
    string name;

    int len = strlen(s);

    while (!is_letter(s[pos]))
        pos++;

    while (is_letter(s[pos]))
        name += s[pos++];

    while (!is_letter(s[pos]))
        pos++;

    if (pos + 3 <= len && s[pos] == 'n' && s[pos + 1] == 'e' && s[pos + 2] == 'w' && s[pos + 3] == ' ') {
        pos += 3;

        vector <int> v;

        read_args(s, pos, v);

        Map[name] = v;

    } else {
        if (Map.count(name))
            Map.erase(name);
        else if (Map1.count(name))
            Map1.erase(name);
                
        string name1;

        while (is_letter(s[pos]))
            name1 += s[pos++];

        vector <int> v;

        read_args(s, pos, v);

        if (!Map.count(name1)) {
            pair <string, int> P = Map1[name1];
            P.S += v[0] - 1;
            Map1[name] = P;
        } else {
            Map1[name] = MP(name1, v[0] - 1);
        }
    }
}

inline void parse_name_and_op(char s[], string& name, string& op, vector <int>& vec) {
    name.clear();    
    op.clear();
    vec.clear();

    int pos = 0;

    while (s[pos] != '.') {
        name += s[pos++];
    }

    pos++;

    while (s[pos] != '(') {
        op += s[pos++];
    }

    read_args(s, pos, vec);

    //cerr << name << ' ' << op << endl;
}

char s[1000000];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    //ios_base :: sync_with_stdio(false);

    scanf("%d", &n);
    
    gets(s);

    vector <int> vec;
    string name, op; 

    stringstream sst;
    
    for (int i = 0; i < n; i++) {
        gets(s);
        //cerr << s << endl;

        /*for (map <string, vector <int> > :: iterator it = Map.begin(); it != Map.end(); it++)
            cerr << it -> F << ' ';

        cerr << endl;*/ 

        if (s[0] == 'L' && s[1] == 'i' && s[2] == 's' && s[3] == 't' && s[4] == ' ') {
            create_new_list(s);
        } else {
            parse_name_and_op(s, name, op, vec);

            if (op == "set") {
                if (Map.count(name)) {
                    Map[name][vec[0] - 1]  = vec[1];
                } else {
                    Map[Map1[name].F][Map1[name].S + vec[0] - 1] = vec[1];
                }
            } else if (op == "add") {
                if (Map.count(name))
                    Map[name].push_back(vec[0]);
            } else if (op == "get") {
                if (Map.count(name)) {
                    sst << Map[name][vec[0] - 1] << endl;
                } else {
                    sst << Map[Map1[name].F][Map1[name].S + vec[0] - 1] << endl;
                }
            }
        }
    }

    cout << sst.str() << endl;

    return 0;
}
