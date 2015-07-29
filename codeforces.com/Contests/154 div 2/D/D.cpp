/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define sqr(x) (x) * (x)
#define INF (int) (2e9)
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

int n, m, k;

char a[500][500];

int count_a[500][500], cur[26][500], len[26];

void Calc() {
    if (a[0][0] == 'a') 
        count_a[0][0] = 1;

    for (int i = 1; i < m; i++) {
        count_a[0][i] = count_a[0][i - 1];
        
        if (a[0][i] == 'a')
            count_a[0][i] ++;
    }

    for (int i = 1; i < n; i++) {
        count_a[i][0] = count_a[i - 1][0];
        
        if (a[i][0] == 'a')
            count_a[i][0]++;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            count_a[i][j] = count_a[i - 1][j] + count_a[i][j - 1] - count_a[i - 1][j - 1];

            if (a[i][j] == 'a')
                count_a[i][j]++;
        }
    }
}  

int count_of_a(int x, int y, int _x, int _y) {
    int ans = count_a[_x][_y];

    if (x > 0)
        ans -= count_a[x - 1][_y];

    if (y > 0)
        ans -= count_a[_x][y - 1];

    if (x > 0 && y > 0)
        ans += count_a[x - 1][y - 1];
    
    return ans;
}

long long solve(int t, int d) {
    long long ans = 0;

    memset(len, 0, sizeof len);

    for (int i = 0; i < m; i++) 
    	if (a[t][i] == a[d][i])
    		cur[a[t][i] - 'a'][len[a[t][i] - 'a']++] = i;

    for (char ch = 'a'; ch <= 'z'; ch++) {
        
        int l = 0, r = 0;

        while (r < len[ch - 'a'] - 1) {
            r++;

            while (count_of_a(t, cur[ch - 'a'][l], d, cur[ch - 'a'][r]) > k && l < r)
                l++;

            ans += (r - l);
        }

    }

    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++)
    	scanf("\n%s", a[i]);

    long long ans = 0;
    Calc();

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << count_a[i][j] << ' ' ;
        cout << endl;   
    }*/

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < i; j++) 
            ans += solve(j, i);

   	printf("%I64d\n", ans);

    return 0;
}