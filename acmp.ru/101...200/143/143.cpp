#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool operator > (string a, string b) {
    int lena = a.length();
    int lenb = b.length();

    if (lena != lenb)
        return lena > lenb;

    for (int i = 0; i < lena; i++) {
        if (a[i] != b[i])
            return a[i] > b[i];
    }

    return false;
}

vector <int> operator - (vector <int> a, const vector <int> &b) {
    int lena = a.size();
    int lenb = b.size();

    for (int i = 0; i < lenb; i++) {
        while (a[i] < b[i]) {
            a[i] += 10;
            a[i + 1]--;
        }

        a[i] -= b[i];
    }

    for (int i = 0; i < lena; i++)
        if (a[i] < 0)
            {
                a[i] += 10;
                a[i + 1] --;
            }
    return a;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s1, s2;

    cin >> s1 >> s2;

    bool f = false;

    if (s2 > s1)
        {
            swap(s1, s2);
            f = true;
        }

    vector <int> a(s1.length());

    for (int i = s1.length() - 1; i >= 0; i--)
        a[i] = (s1[i] - '0');

    vector <int> b(s2.length());

    for (int i = s2.length() - 1; i >= 0; i--)
        b[i] = (s2[i] - '0');

    if (a == b)
        {
            cout << 0;
            return 0;
        }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    a = a - b;

    int pos = s1.length() - 1;

   while (a[pos] == 0 && pos > 0)
    {    
        pos--;
    }


    if (f)
        cout << '-';

    while (pos >= 0)
        cout << a[pos--];

    cout << endl;
    
    return 0;   
}
