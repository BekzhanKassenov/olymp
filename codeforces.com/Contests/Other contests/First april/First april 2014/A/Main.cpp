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
    Map["[]"] = 1;
    Map["8<"] = 2;
    
    int cnt1 = 0, cnt2 = 0;
    
    for (int i = 0; i < len; i += 2) {
        string s1 = s.substr(i, 2);
        string t1 = t.substr(i, 2);
        
        //cout << s1 << ' ' << t1 << ' ' << (Map[s1] < Map[t1]) << endl; 
        
        if (Map[s1] < Map[t1])
            cnt2++;
        else if (Map[t1] < Map[s1])
            cnt1++;  
    }
    
    if (cnt1 > cnt2)
        cout << "TEAM 1 WINS";
    else if (cnt2 > cnt1)
        cout << "TEAM 2 WINS";
    else
        cout << "TIE";
    
    return 0;
}
