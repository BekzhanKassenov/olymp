#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int MAXN = 1510;

ll sqr(ll a) {
    return a * a;
}

struct Point {
    ll x, y;

    Point() { }

    Point(ll x, ll y) : x(x), y(y) { }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    int read() {
        return scanf("%I64d%I64d", &x, &y);
    }

    long long dist(const Point& p) const {
        return sqr(x - p.x) + sqr(y - p.y);
    }

    bool operator < (const Point& p) const {
        if (x != p.x)
            return x < p.x;

        return y < p.y;
    }
};

ostream& operator << (ostream& c, const Point& p) {
    cout << '{' << p.x << ", " << p.y << '}';
    return c;
}

Point p[MAXN];
int n, ans;

bool cmp(int a, int b) {
    return p[a] < p[b];
}

map <long long, vector <int> > Map;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        p[i].read();

    for (int i = 0; i < n; i++) {
        Map.clear();

        const Point& center = p[i];

        for (int j = 0; j < n; j++) {
            if (i != j) {
                long long dist = p[i].dist(p[j]);
                Map[dist].push_back(j);
            }
        }

        for (map <long long, vector <int> > :: iterator it = Map.begin(); it != Map.end(); it++) {
            vector <int>& vec = it -> second;
            int size = vec.size();

            if (size == 1)
                continue;

            sort(all(vec), cmp);

            for (size_t j = 0; j < vec.size(); j++) {
                const Point& current = p[vec[j]];

                Point delta = center - current;
                Point opposite = center + delta;
                p[n] = opposite;
                
                if (binary_search(all(vec), n, cmp))
                    ans += size - 2;
                else
                    ans += size - 1;
            }
        }

        /*cout << center << ' ' << ans << endl;

        for (map <long long, vector <int> > :: iterator it = Map.begin(); it != Map.end(); it++) {
            cout << it -> first << endl;

            const vector <int>& vec = it -> second;

            for (size_t i = 0; i < vec.size(); i++)
                cout << p[vec[i]] << ' ';

            cout << endl;
        }

        cout << endl;*/
    }

    printf("%d\n", ans / 2);

    return 0;
}
