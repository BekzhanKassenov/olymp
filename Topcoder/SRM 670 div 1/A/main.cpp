/****************************************
**     Solution by Bekzhan Kassenov    **
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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

class Bracket107 {
    size_t match[100];
    set <string> ans;

    bool correct(const string& s) {
        int bal = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                bal++;
            } else {
                bal--;
            }

            if (bal < 0) {
                return false;
            }
        }

        return bal == 0;
    }

    void calc1(const string& s) {
        string temp;

        for (size_t i = 0; i <= s.size(); i++) {
            for (size_t j = i; j <= s.size(); j++) {
                temp.clear();

                for (size_t k = 0; k < s.size(); k++) {
                    if (i == k) {
                        temp.append(1, '(');
                    }

                    if (j == k) {
                        temp.append(1, ')');
                    }

                    temp.append(1, s[k]);
                }

                if (correct(temp)) {
                    ans.insert(temp);
                }
            }
        }
    }

    void calc2(const string& s) {
        for (size_t i = 0; i < s.size(); i++) {
            string temp1, temp2;

            for (size_t j = 0; j < s.size(); j++) {
                if (j == i) {
                    temp1.append(1, '(');
                    temp2.append(1, ')');
                }

                temp1.append(1, s[j]);
                temp2.append(1, s[j]);
            }


            if (correct(temp1)) {
                ans.insert(temp1);
            }

            if (correct(temp2)) {
                ans.insert(temp2);
            }
        }
    }
public:
    int yetanother(string s) {
        vector <int> st;

        memset(match, 0, sizeof match);

        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push_back(i);
            } else {
                match[st.back()] = i;
                st.pop_back();
            }
        }

        for (size_t i = 0; i < s.size(); i++) {
            string temp;

            for (size_t j = 0; j < s.size(); j++) {
                if (i != j) {
                    temp.append(1, s[j]);
                }
            }

            calc2(temp);
        }

        if (ans.count(s)) {
            ans.erase(s);
        }

        if (!ans.empty()) {
            return ans.size();
        }

        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                string temp;
                for (size_t j = 0; j < s.size(); j++) {
                    if (j != i && j != match[i]) {
                        temp.append(1, s[j]);
                    }
                }

                calc1(temp);
            }
        }   

        if (ans.count(s)) {
            ans.erase(s);
        }

        for (auto it: ans) {
            cerr << it << endl;
        }

        return ans.size();
    }
};

void call(const string& s) {
    Bracket107 b;

    cout << b.yetanother(s) << endl;
}

int main() {
    call("((())())((())())((())())((())())((())())((())())((())())((())())((())())");
    
    return 0;
}