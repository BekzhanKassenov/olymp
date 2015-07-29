#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

const int scores[] = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5};
const char modifiers[] = {0, 'D', 'T'};

struct Hit {
    int score;
    char modifier;

    Hit() {
        score = 1;
        modifier = 0;
    }

    void next() {
        if (score == 25) {
            score = 50;
        } else if (score == 50) {
            score = 0;
        } else {
            int modifierpos = -1;
            for (int i = 0; i < 3; i++) {
                if (modifiers[i] == modifier) {
                    modifierpos = i;
                }
            }

            score++;
            if (score == 21) {
                score = 1;
                modifierpos++;

                if (modifierpos == 3) {
                    score = 25;
                    modifier = 0;
                } else {
                    modifier = modifiers[modifierpos];
                }
            }
        }
    }

    bool can_be_last() const {
        return modifier == 'D' || score == 50;
    }

    void output(stringstream& ss) {
        if (score == 50) {
            ss << "Bull";
        } else {
            if (modifier != 0) {
                ss << modifier;
            }

            ss << score;
        }
    }

    int get_score() {
        if (modifier == 'D') {
            return score * 2;
        }

        if (modifier == 'T') {
            return score * 3;
        }

        return score;
    }
};

stringstream ans;
int anscnt, n;
Hit st[3];

void go(int score, int lev = 0) {
    if (score == 0 && st[lev - 1].can_be_last()) {
        anscnt++;
        for (int i = 0; i < lev; i++) {
            st[i].output(ans);
            if (i != lev - 1) {
                ans << ' ';
            } else {
                ans << endl;
            }
        }
    }

    if (lev == 3) {
        return;
    }

    for (Hit it; it.score != 0; it.next()) {
        st[lev] = it;
        go(score - it.get_score(), lev + 1);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    go(n);

    printf("%d\n%s\n", anscnt, ans.str().c_str());


    return 0;
}
