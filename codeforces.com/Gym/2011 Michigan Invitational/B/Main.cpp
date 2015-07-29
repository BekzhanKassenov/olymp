/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int BASE = 67;
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int cas;
int n;
string aa, bb, cc;
map <string, int> cnt;
set <string> artist, album, song;

bool cmp(const string& a, const string& b) {
    return cnt[a] < cnt[b];
}

vector <string> a[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    while ((cin >> n) && n) {
        cnt.clear();
        artist.clear();
        album.clear();
        song.clear();
        cas++;

        for (int i = 0; i < n; i++) {
            a[i].resize(3);

            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
                cnt[a[i][j]]++;
            }
        }

        for (int i = 0; i < n; i++)
            sort(all(a[i]), cmp);

        for (int i = 0; i < n; i++) {
            int cnt0 = cnt[a[i][0]];
            int cnt1 = cnt[a[i][1]];
            int cnt2 = cnt[a[i][2]];

            if (cnt2 == 1) {
                for (int j = 0; j < 3; j++) {
                    artist.insert(a[i][j]);
                    album.insert(a[i][j]);
                    song.insert(a[i][j]);
                }
            } else if (cnt0 == 1 && cnt1 == 1) {
                artist.insert(a[i][2]);
                
                album.insert(a[i][0]);
                song.insert(a[i][1]);

                album.insert(a[i][1]);
                song.insert(a[i][0]);
            } else if (cnt1 == cnt2) {
                song.insert(a[i][0]);

                artist.insert(a[i][2]);
                album.insert(a[i][1]);
            
                artist.insert(a[i][1]);
                album.insert(a[i][2]);
            } else {
                song.insert(a[i][0]);
                album.insert(a[i][1]);
                artist.insert(a[i][2]);
            }
        }

        printf("Case %d: %u %u %u\n", cas, artist.size(), album.size(), song.size());
    }
    
    return 0;
}
