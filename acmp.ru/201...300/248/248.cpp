#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>

using namespace std;

vector <string> tokenize(const string& s) {
    vector <string> tokens;
    string token;

    for (char c : s) {
        if (!isalpha(c)) {
            if (!token.empty()) {
                tokens.emplace_back(token);
            }
            token.clear();
            token.push_back(c);
            tokens.emplace_back(token);
            token.clear();
        } else {
            token.push_back(c);
        }
    }

    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}

bool endsWith(const string& a, const string& b) {
    if (a.size() < b.size()) {
        return false;
    }

    size_t start = a.size() - b.size();
    for (size_t i = start; i < a.size(); i++) {
        if (tolower(a[i]) != tolower(b[i - start])) {
            return false;
        }
    }

    return true;
}

bool equalsLower(const string& a, const string& b) {
    if (a.size() != b.size()) {
        return false;
    }

    return endsWith(a, b);
}

void doPhase(string& word, const vector <pair <string, string> >& repl) {
    if (word.empty() || !isalpha(word[0])) {
        return;
    }

    bool wasCapital = isupper(word[0]);

    string temp;
    for (char c : word) {
        temp.push_back(c);

        bool worked;
        do {
            worked = false;
            for (const auto& p : repl) {
                if (endsWith(temp, p.first)) {
                    for (size_t i = 0; i < p.first.size(); i++) {
                        temp.pop_back();
                    }

                    temp += p.second;
                    worked = true;
                    break;
                }
            }
        } while (worked);
    }

    word = temp;
    if (wasCapital) {
        word[0] = toupper(word[0]);
    }
}

void killArticles(string& word) {
    for (const string art : {"a", "an", "the"}) {
        if (equalsLower(word, art)) {
            word.clear();
            return;
        }
    }
}

void phaseOne(string& word) {
    static vector <pair <string, string> > repl {
        {"ci", "si"},
        {"ce", "se"},
        {"ck", "k"},
    };

    doPhase(word, repl);
    for (char& c : word) {
        if (tolower(c) == 'c') {
            if (islower(c)) {
                c = 'k';
            } else {
                c = 'K';
            }
        }
    }
}

void phaseTwo(string& word) {
    static vector <pair <string, string> > repl;
    if (repl.empty()) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (c == 'e') {
                repl.emplace_back(string(2, c), "i");
            } else if (c == 'o') {
                repl.emplace_back(string(2, c), "u");
            } else {
                repl.emplace_back(string(2, c), string(1, c));
            }
        }
    }

    doPhase(word, repl);
}

void phaseThree(string& s) {
    if (s.size() > 1u && tolower(s.back()) == 'e') {
        s.pop_back();
    }
}   

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    getline(cin, s);

    vector <string> spaced;
    
    string temp;
    for (char c : s) {
        if (c == ' ') {
            if (!temp.empty()) {
                spaced.emplace_back(temp);
            }
            temp.clear();
        } else {
            temp.push_back(c);
        }
    }

    if (!temp.empty()) {
        spaced.emplace_back(temp);
    }

    for (string& token: spaced) {
        vector <string> words(tokenize(token));
        token.clear();
        for (string& word : words) {
            killArticles(word);
            phaseOne(word);
            phaseTwo(word);
            phaseThree(word);
            token += word;
        }
    }
                
    vector <string> res;
    for (const string& token : spaced) {
        if (!token.empty()) {
            res.emplace_back(token);
        }
    }

    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i + 1 < res.size()) {
            cout << ' ';
        }
    }

    cout << endl;

    return 0;
}
