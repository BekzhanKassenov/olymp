#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>
#include <cstdio>
#include <queue>

using namespace std;

#define maxn 1000010

struct vertex {
    map <char, int> next;
    char pch;
    int link, par;
    map <char, int> go;
    bool leaf;    
};

vertex trie[maxn];
int sz = 2;

void init() {
    for (char i = 32; i <= 126; i++)
        trie[0].next[i] = 1;
        
    trie[1].par = trie[1].link = 0;
    trie[0].leaf = trie[1].leaf = 0;
    trie[0].pch = trie[1].pch = 0;
}

void add_string(const string& s) {
    int cur = 1;
    
    for (size_t i = 0; i < s.size(); i++) {
        if (!trie[cur].next.count(s[i])) {
            trie[sz].pch = s[i];
            trie[sz].par = cur;
            trie[cur].next[s[i]] = sz;
            trie[sz].link = -1;
            sz++;
        }
        
        cur = trie[cur].next[s[i]];
    }
    
    trie[cur].leaf = true;
}

int go(int v, char c);

int get_link(int v) {
    int pr = trie[v].par;
    
    if (trie[v].link < 0)
        trie[v].link = go(get_link(pr), trie[v].pch);
    
    return trie[v].link;
}

int go(int v, char c) {
    cerr << v << ' ' << c << endl;
    if (trie[v].go.count(c))
        return trie[v].go[c];
        
    if (trie[v].next.count(c))
        return trie[v].go[c] = trie[v].next[c];
        
    return trie[v].go[c] = go(get_link(v), c);
}

void bfs() {
    queue <int> q;
    q.push(1);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        cerr << q.size() << endl;
        
        int link = get_link(v);
        
        cerr << "ASD" << endl;
        
        trie[v].leaf |= trie[link].leaf;
            
        for (char i = 32; i <= 126; i++) {
            trie[v].go[i] = go(v, i);
        }
        
        for (map <char, int> :: iterator it = trie[v].next.begin(); it != trie[v].next.end(); it++) {
            q.push(it -> second);
        }
    }
}

bool get_ans(const string& s) {
    int cur = 1;
    bool flag = false;
     
    for (size_t i = 0; i < s.size(); i++) {
        cur = trie[cur].go[s[i]];
        flag |= trie[cur].leaf;
    }
    
    return flag;
}

int main() {
    freopen("console.in", "r", stdin);
    freopen("console.out", "w", stdout);
    
    ios_base :: sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    init();
    
    string s;
    
    getline(cin, s);
    
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        add_string(s);
    }
    
    bfs();
    
    while (getline(cin, s)) {
        if (get_ans(s))
            cout << s << endl;    
    }
    
    return 0;
}
