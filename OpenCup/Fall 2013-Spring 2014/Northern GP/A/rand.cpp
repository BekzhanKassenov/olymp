#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

const int N = 50;

map <vector <char>, vector <char> > Map;

bool cmp (const vector <int>& lhs, const vector <int>& rhs) {
    for (size_t i = 0; i < lhs.size(); i++)
        if (lhs[i] != rhs[i])
            return false;

    return true; 
}

bool check(const vector <int>& a, const vector <int>& b) {
    int lena = a.size();
    
    vector <int> s1;
    s1.reserve(lena * (lena - 1) / 2);
    
    vector <int> s2;
    s2.reserve(lena * (lena - 1) / 2);
    
    for (int i = 0; i < lena; i++) {
        for (int j = i + 1; j < lena; j++) {
            s1.push_back(a[i] + a[j]);
            s2.push_back(b[i] + b[j]);   
        }
    }
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    for (int i = 0; i < lena * (lena - 1) / 2; i++)
        cout << s1[i] << ' ';
   
    cout << endl;
    
    for (int i = 0; i < lena * (lena - 1) / 2; i++)
        cout << s2[i] << ' ';
        
    return cmp(s1, s2);
}

int main() {
    freopen("analogous.out", "r", stdin);
    
    int n;
    cin >> n;
    vector <int> v1(n), v2(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    
    for (int i = 0; i < n; i++)
        cin >> v2[i];
    
    if (check(v1, v2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }   
    vector <char> a(6);
    
/*   for (a[0] = 1; a[0] <= N; a[0]++) {
        for (a[1] = a[0] + 1; a[1] <= N; a[1]++) {
            for (a[2] = a[1] + 1; a[2] <= N; a[2]++) {
                for (a[3] = a[2] + 1; a[3] <= N; a[3]++) {
                    for (a[4] = a[3] + 1; a[4] <= N; a[4]++) {
                        for (a[5] = a[4] + 1; a[5] <= N; a[5]++) {
                            vector <char> b;
                            b.reserve(15);
                    
                            for (char i = 0; i < 6; i++) {
                                for (char j = i + 1; j < 6; j++)
                                    b.push_back(a[i] + a[j]);
                            }
                        
                            sort(b.begin(), b.end());
                    
                            if (Map.count(b)) {
                                cout << "Match found" << endl;
                        
                                for (char i = 0; i < 6; i++)
                                    cout << a[i] << ' ';
                            
                                cout << endl;
                        
                                for (char i = 0; i < 6; i++)
                                    cout << Map[b][i] << ' ';
                                cout << endl;
                        
                                cout << "A + A" << endl;
                        
                                for (char i = 0; i < 15; i++)
                                    cout << b[i] << ' ';
                            
                                cout << endl << endl;
                                return 0;
                            } else {
                                Map[b] = a;
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << "No matches found" << endl;
  */  
    return 0;
}
