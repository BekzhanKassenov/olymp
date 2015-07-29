#include <iostream>
#include <cstdio>
#include <string>
#include <set>

using namespace std;

int model1(set <string> set1, set <string> set2) {
    int score1 = 0;
    int score2 = 0;
    int common = 0;

    for (set <string>::iterator it = set1.begin(); it != set1.end(); it++) {
        if (set2.count(*it)) {
            common++;
        }
    }

    int size1 = set1.size() - common;
    int size2 = set2.size() - common;
    int move1 = true;

    while (common > 0 || size1 > 0 || size2 > 0) {
        if (move1) {
            if (common > 0) {
                score1++;
                common--;
            } else if (size1 > 0) {
                score1++;
                size1--;
            }
        } else {
            if (common > 0) {
                score2++;
                common--;
            } else if (size2 > 0) {
                score2++;
                size2--;
            }
        }

        move1 ^= true;
    }

    if (score1 > score2) {
        return 1;
    } else if (score1 < score2) {
        return 2;
    }
    
    return 0;
}

int model2(set <string> set1, set <string> set2) {
    int score1 = 0;
    int score2 = 0;
    int common = 0;

    for (set <string>::iterator it = set1.begin(); it != set1.end(); it++) {
        if (set2.count(*it)) {
            common++;
        }
    }

    int size1 = set1.size() - common;
    int size2 = set2.size() - common;
    int move1 = true;

    while (common > 0 || size1 > 0 || size2 > 0) {
        if (move1) {
            if (common > 0) {
                score1++;
                common--;
            } else if (size1 > 0) {
                score1++;
                size1--;
            }
        } else {
            if (size2 > 0) {
                score2++;
                size2--;
            } else if (common > 0) {
                score2++;
                common--;
            }
        }

        move1 ^= true;
    }

    if (score1 > score2) {
        return 1;
    } else if (score1 < score2) {
        return 2;
    }
    
    return 0;
}

string temp;
int n;
set <string> set1, set2;

int main() {
    ios_base::sync_with_stdio(false);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> temp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        set1.insert(temp);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        set2.insert(temp);
    }

    cout << model1(set1, set2) << endl;
    cout << (3 - model2(set2, set1)) % 3 << endl;
    cout << model2(set1, set2) << endl;
    
    return 0;
}
