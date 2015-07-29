/****************************************
**          Solution by NU #2          **
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

char color(char s[]) {
    return s[0];
}

bool isroman(char s[]) {
    return s[2] == 'V' || s[2] == 'I';
}

bool isdigit(char s[]) {
    return isdigit(s[2]);
}

bool isdot(char s[]) {
    return s[2] == '.';
}

char rom[10][10] = {"", "I", "II", "III", "IV", "V", "VI"};

int getnum(char s[]) {
    int result = 0;
    if (isdot(s)) {
        for (int i = 2; s[i]; i++) {
            result++;
        }

    } else if (isdigit(s)) {
        return s[2] - '0';
    } else {
       for (int i = 1; i <= 6; i++) {
           if (strcmp(s + 2, rom[i]) == 0) {
               result = i;
               break;
           }
       }
    }

    return result;
}

bool prime(int x) {
    return x == 2 || x == 3 || x == 5;
}

char a[3][100];

bool John() {
    bool result = true;
    for (int i = 0; i < 3; i++) {
        if (!isdot(a[i])) {
            result = false;
        }
    }

    return result;
}

bool David() {
    bool result = true;
    for (int i = 0; i < 3; i++) {
        if (isroman(a[i])) {
            result = false;
        }
    }

    return result;
}

bool Peter() {
    bool result = true;
    for (int i = 0; i < 3; i++) {
        if (color(a[i]) != 'W') {
            result = false;
        }
    }

    return result;
}

bool Robert() {
    bool result = true;
    for (int i = 0; i < 3; i++) {
        if (color(a[i]) != 'W' && color(a[i]) != 'B') {
            result = false;
        }
    }

    return result;
}

bool Mark() {
    bool result = true;
    for (int i = 0; i < 3; i++) {
        if (getnum(a[i]) % 2 == 1 && color(a[i]) != 'W') {
            result = false;
        }

        if (getnum(a[i]) % 2 == 0 && color(a[i]) != 'B') {
            result = false;
        }

        //cout << getnum(a[i]) << ' ' << color(a[i]) << endl;
    }

    return result;
}

bool Paul() {
    bool result = true;
    for (int i = 0; i < 3; i++) {
        int num = getnum(a[i]);

        //cout << num << ' ' << prime(num) << ' ' << isdigit(a[i]) << endl;

        if (prime(num) && !isdigit(a[i])) {
            result = false;
        }

        if (isdigit(a[i]) && !prime(num)) {
            result = false;
        }
    }

    return result;
}

bool Patrick() {
    bool result = true;
    char cc = 0;
    for (int i = 0; i < 3; i++) {
        if (color(a[i]) != 'W' && color(a[i]) != 'B') {
            if (cc == 0) {
                cc = color(a[i]);
            }

            if (cc != color(a[i])) {
                result = false;
            }
        } else {
            result = false;
        }
    }

    return result;
}

bool Jack() {
    bool result = true;
    for (int i = 0; i < 3; i++) {
        if (isroman(a[i]) && color(a[i]) != 'Y') {
            result = false;
        }
    }

    return result;
}

bool Max() {
    set <char> Set;
    for (int i = 0; i < 3; i++) {
        Set.insert(color(a[i]));
    }

    return Set.size() == 3u;
}

bool Alex() {
    bool result = true;
    char type[3] = {0, 0, 0};
    
    for (int i = 0; i < 3; i++) {
        if (isroman(a[i]) && type[0] == 0) {
            type[0] = color(a[i]);
        } else if (isdigit(a[i]) && type[1] == 0) {
            type[1] = color(a[i]);
        } else if (isdot(a[i]) && type[2] == 0) {
            type[2] = color(a[i]);
        }
    }

    for (int i = 0; i < 3; i++) {
        if (isroman(a[i])) {
            result &= type[0] == color(a[i]);
        } else if (isdigit(a[i])) {
            result &= type[1] == color(a[i]);
        } else if (isdot(a[i])) {
            result &= type[2] == color(a[i]);
        }
    }

    for (int i = 0; i < 3; i++) {
        if (type[i] != 0) {
            for (int j = 0; j < 3; j++) {
                if (type[j] != 0 && i != j) {
                    if (type[i] == type[j]) {
                        result = false;
                    }
                }
            }
        }
    }

    return result;
}


char name[10][50] = {"John", 
                     "David", 
                     "Peter", 
                     "Robert",
                     "Mark",
                     "Paul",
                     "Patrick",
                     "Jack",
                     "Max",
                     "Alex"
                    };
bool used[10];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 3; i++) {
        gets(a[i]);
    }

    if (John())    used[0] = true;   
    if (David())   used[1] = true;
    if (Peter())   used[2] = true;
    if (Robert())  used[3] = true;
    if (Mark())    used[4] = true;   
    if (Paul())    used[5] = true;
    if (Patrick()) used[6] = true;
    if (Jack())    used[7] = true;
    if (Max())     used[8] = true;
    if (Alex())    used[9] = true;

    for (int i = 0; i < 10; i++) {
        if (used[i]) {
            printf("%s ", name[i]);
        }
    }

    puts("");
    return 0;
}
