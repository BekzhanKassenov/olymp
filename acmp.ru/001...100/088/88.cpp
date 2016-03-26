#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;

bool check(vector <int> a)
{
    for (int i = 0; i < n * n; i++)
        if (a[i] != 1)
            return false;

    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;

    vector <vector <int> > a(n * n, vector <int> (n * n));

    for (int i = 0; i < n * n; i++) {
        for (int j = 0; j < n * n; j++) {
            cin >> a[i][j];

            if (a[i][j] > n * n || a[i][j] < 1) {
                cout << "Incorrect" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < n * n; i++)
        {
            vector <int> a1(n * n), a2(n * n);

            for (int j = 0; j < n * n; j++)
                {
                    a1[a[i][j] - 1]++;
                    a2[a[j][i] - 1]++;
                }

            if (!check(a1) || !check(a2))
                {
                    cout << "Incorrect";
                    return 0;
                }   
        }

    for (int i = 0; i < n * n; i += n)
        {
            for (int j = 0; j < n * n; j += n)
                {
                    vector <int> a1(n * n);

                    for (int x = i; x < i + n; x++)
                        for (int y = j; y < j + n; y++)
                            a1[a[x][y] - 1]++;

                    if (!check(a1))
                        {
                            cout << "Incorrect";
                            return 0;
                        }
                }
        }

    cout << "Correct";
    return 0;
}
