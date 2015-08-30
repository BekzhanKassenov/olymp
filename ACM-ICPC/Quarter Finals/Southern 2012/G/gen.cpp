#include <bits/stdc++.h>

using namespace std;

vector <string > keyval;

string genString() {
    int len = rand() % 5 + 1;
    string all = "0123456789abcdefghijklmnopqrstuvwxyz";

    string res;

    for (int i = 0; i < len; i++) {
        res += all[rand() % all.length()];
    }

    return res;
}

int main() {
    srand(time(NULL));

    freopen("input.txt", "w", stdout);

    int n = rand() % 15 + 1;
    int m = rand() % 25 + 1;

    for (int i = 0; i < n * m; i++) {
        keyval.push_back(genString());    
    }

    cout << n << endl;
    
    for (int i = 0; i < n; i++) {
        int k = rand() % 4 + 1;
        cout << k << " ";
        for (int j = 0; j < k; j++) {
            cout << keyval[rand() % keyval.size()] << "=" << keyval[rand() % keyval.size()] << " ";
        }
        cout << endl;
    }
    

    cout << m << endl;

    for (int i = 0; i < m; i++) {
        int k = rand() % 4 + 1;
        cout << k << " ";
        for (int j = 0; j < k; j++) {
            cout << keyval[rand() % keyval.size()] << "=" << keyval[rand() % keyval.size()] << " ";
        }
        cout << endl;
    }



    return 0;
}
