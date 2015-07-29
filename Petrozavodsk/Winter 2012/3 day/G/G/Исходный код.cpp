#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int a[3000];
vector< pair<int, int> > b;
int main(){
    freopen("sandwiches.in", "r", stdin);
    int x, k, t;
    cin >> t;
    while (t){
    --t;
    cin >> k;
    b.clear();
    for (int i = 0; i < k; ++i){
        a[i] = -1000000000;
        for (int j = 0; j < k; ++j){
            cin >> x;
            if (x > a[i]){
                if (a[i] != -1000000000)
                    b.push_back(make_pair(a[i], i));
                a[i] = x;
            }
            else
            b.push_back(make_pair(x, i));
        }
        }
    
    int sum = 0;
        for (int i = 0; i < k; ++i)
            sum += a[i];
        for (int i = 0; i < b.size(); ++i)
            b[i].first = a[b[i].second] - b[i].first;
        sort(b.begin(), b.end());
        cout << sum << " ";
        for (int i = 0; i < k-1; ++i){
            cout << sum - b[i].first << " ";
        }
        cout << endl;
    }

return 0;
}