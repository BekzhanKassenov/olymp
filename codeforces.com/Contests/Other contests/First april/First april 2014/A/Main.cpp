#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    string s, t;
    cin >> s >> t;
    
    int len = s.size();
    
    map <string, int> Map;

    Map["()"] = 0;
    Map["8<"] = 1;
    Map["[]"] = 2;
    
    int cnt1 = 0, cnt2 = 0;
    
    for (int i = 0; i < len; i += 2) {
        string s1 = s.substr(i, 2);
        string t1 = t.substr(i, 2);
        
        int p1 = Map[s1];
        int p2 = Map[t1];
        if ((p1 + 1) % 3 == p2) {
            cnt1++;
        } else if ((p2 + 1) % 3 == p1) {
            cnt2++;
        }                    
    }
    
    if (cnt1 > cnt2)
        cout << "TEAM 1 WINS" << endl;
    else if (cnt2 > cnt1)
        cout << "TEAM 2 WINS" << endl;
    else
        cout << "TIE" << endl;
    
    return 0;
}
