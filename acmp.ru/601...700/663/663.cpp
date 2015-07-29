#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct entry {
    string name;
    string problem;
    int score;

    void parse(const string& s) {
        int pos = 0;
        int len = s.size();

        while (pos < len && s[pos] != '-') {
            name.append(1, s[pos]);
            pos++;
        }

        pos++;

        while (pos < len && s[pos] != '-') {
            problem.append(1, s[pos]);
            pos++;
        }

        pos++;
        score = 0;

        while (pos < len) {
            score *= 10;
            score += s[pos] - '0';
            pos++;
        }
    }

    bool satisfies(const string& s, const string& t) {
        return entry::equal(name, s) && entry::equal(name, t);
    }

    bool equal(const string& s, const string& t) {
        if (s.size() != t.size())
            return false;

        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '?' || t[i] == '?')
                continue;

            if (s[i] != t[i])
                return false;
        }

        return true;
    }
};

int n, m, k;
string fname[15], prname[15];
int cnt, friends;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> fname[i];

    for (int i = 0; i < m; i++)
        cin >> pname[i];

    cin >> k;



    return 0;
}

