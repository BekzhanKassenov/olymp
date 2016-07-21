#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>

using namespace std;

int n;
string op;
string arg1, arg2;
map <string, string> data;
set <string> loggedin;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == "register") {
            cin >> arg1 >> arg2;
            if (data.count(arg1)) { 
                cout << "fail: user already exists" << endl;
            } else {
                cout << "success: new user added" << endl;
                data[arg1] = arg2;
            }
        } else if (op == "login") {
            cin >> arg1 >> arg2;
            if (!data.count(arg1)) {
                cout << "fail: no such user" << endl;
            } else if (data[arg1] != arg2) {
                cout << "fail: incorrect password" << endl;
            } else if (loggedin.count(arg1)) {
                cout << "fail: already logged in" << endl;
            } else {
                loggedin.insert(arg1);
                cout << "success: user logged in" << endl;
            }
        } else if (op == "logout") {
            cin >> arg1;
            if (!data.count(arg1)) {
                cout << "fail: no such user" << endl;
            } else if (!loggedin.count(arg1)) {
                cout << "fail: already logged out" << endl;
            } else {
                loggedin.erase(arg1);
                cout << "success: user logged out" << endl;
            }
        }
    }

    return 0;
}
