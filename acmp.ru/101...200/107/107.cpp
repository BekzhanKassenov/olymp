#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define all(x) (x).begin(), (x).end()

map <string, int> beauty;
string s;
int n, ans, anspos;

int len[5][5] = {{2, 2, 3},
                 {2, 3, 2},
                 {3, 2, 2},
                 {4, 3},
                 {3, 4}};

inline void build() {
    beauty["aa"  ] = 2;
    beauty["aba" ] = 2;
    beauty["aab" ] = 2;
    beauty["abb" ] = 2;
    beauty["aaa" ] = 3;
    beauty["abac"] = 2;
    beauty["abcb"] = 2;
    beauty["abab"] = 3;
    beauty["aabb"] = 3;
    beauty["abba"] = 4;
    beauty["abbb"] = 3;
    beauty["abaa"] = 3;
    beauty["aaba"] = 3;
    beauty["aaab"] = 3;
    beauty["aaaa"] = 5;
}

string get_pattern(const string& s) {
    string result;
    char last = 'a';
    map <char, char> Map;

    for (size_t i = 0; i < s.size(); i++) {
        if (!Map.count(s[i])) {
            Map[s[i]] = last++;
        }
        
        result += Map[s[i]];
    }

    return result;
}

int eval(int num) {
    int result = 0;
    string cur;
    int pos = 0;
    int ptr = 0;

    while (pos < n) {
        for (int i = 0; i < len[num][ptr]; i++) {
            cur += s[pos++];
        }

        ptr++;
        result += beauty[get_pattern(cur)];
        cur.clear();
    }

    return result;
}

void print(int num) {
    string result;
    int pos = 0;
    int ptr = 0;

    while (pos < n) {
        for (int i = 0; i < len[num][ptr]; i++) {
            result += s[pos++];
        }

        ptr++;
        if (pos != n) {
            result += '-';
        }
    }

    cout << result << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    build();

    cin >> s;
    n = s.size();

    for (int i = 0; i < 5; i++) {
        int _beauty = eval(i);

        if (ans < _beauty) {
            ans = _beauty;
            anspos = i;
        }
    }

    print(anspos);
    cout << ans << endl;

    return 0;
}
