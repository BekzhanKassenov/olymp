/********************************************
***     Solution by Bekzhan Kassenov      ***
********************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define sqr(x) (x) * (x)
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define ll long long
#define ull unsigned long long
#define INF
#define MOD
#define EPS

vector <int> a(26), b(26);

int main()
{

    string s, t;

    cin >> s >> t;

    int lena = t.size();

    int lenb = s.size();

    for (int i = 0; i < (int)t.length(); i++)
        {
            a[t[i] - 'a']++;
            b[s[i] - 'a']++;

        }

    for (int i = lena; i < lenb; i++)
        {
            if (a == b)
                {
                    cout << "YES";
                    return 0;
                }

            b[s[i - 1] - len]++;
        }


    return 0;
}
