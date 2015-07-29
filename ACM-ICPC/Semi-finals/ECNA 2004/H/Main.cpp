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
typedef vector <bool> row;
typedef vector <row> matrix;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Graph {
    int n;
    matrix adj;
    map <string, int> num;
    vector <string> word;
    vector <int> in_degree;
    vector <int> out_degree;

    void read(int input_size) {
        vector <pair <string, string> > buf(input_size);
        word.reserve(2 * input_size);

        for (int i = 0; i < input_size; i++) {
            cin >> buf[i].first >> buf[i].second;
            
            word.push_back(buf[i].first);
            word.push_back(buf[i].second);
        }

        sort(all(word));
        word.resize(unique(all(word)) - word.begin());
        n = word.size();

        for (int i = 0; i < n; i++) {
            num[word[i]] = i;
        }

        adj.assign(n, row(n));
        in_degree.assign(n, 0);
        out_degree.assign(n, 0);

        for (int i = 0; i < input_size; i++) {
            adj[num[buf[i].first]][num[buf[i].second]] = true;
            out_degree[num[buf[i].first]]++;
            in_degree[num[buf[i].second]]++;
        }
    }

    void clear() {
        n = 0;
        adj.clear();
        word.clear();
        num.clear();
        in_degree.clear();
        out_degree.clear();
    }
};

int N;
Graph G, H;
bool found;
bool used[26];
int mapped_to[26];

inline bool check() {
    int n = G.n;
    matrix new_G(n, row(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G.adj[i][j]) {
                new_G[mapped_to[i]][mapped_to[j]] = true;
            }
        }
    }

    return new_G == H.adj;
}

inline bool refine(matrix& mat) {
    bool result = true;
    bool refined = false;

    do {
        refined = false;
        
        for (int i = 0; i < H.n; i++) { // vertex in H
            for (int j = 0; j < G.n; j++) { // vertex in G
                if (!mat[i][j]) {
                    continue;
                }
                
                for (int k = 0; k < G.n; k++) {
                    if (mapped_to[k] != -1) {
                        if (G.adj[i][k] != H.adj[j][mapped_to[k]] ||
                            G.adj[k][i] != H.adj[mapped_to[k]][j]) {
                            mat[i][j] = false;
                            refined = true;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < H.n; i++) { // vertex in H
            bool has_one = false;

            for (int j = 0; j < G.n; j++) { // vertex in G
                if (!mat[i][j]) {
                    continue;
                }
                
                has_one = true;
                bool ok = true; // false if we should set mat[i][j] to 0

                for (int k = 0; k < H.n && ok; k++) {
                    if (!H.adj[i][k] || used[k]) {
                        continue;
                    }

                    bool found = true;
                    for (int l = 0; l < G.n && found; l++) {
                        if (G.adj[j][l] && mapped_to[l] == -1) {
                            found |= mat[k][l];
                        }
                    }

                    ok &= found;
                }

                if (!ok) {
                    mat[i][j] = 0;
                    refined = true;
                    result = true;
                }
                
            }

            if (!has_one) {
                return false;
            }
        }
    } while (refined);
    
    return result;
}

inline void attempt(int v, matrix& mat) {
    if (v == G.n) {
        if (check()) {
            for (int i = 0; i < G.n; i++) {
                cout << G.word[i] << '/' << H.word[mapped_to[i]] << endl;
            }
            cout << endl;

            found = true;
        }

        return;
    }

    if (!refine(mat)) {
        return;
    }

    matrix temp(mat);

    for (int i = 0; i < H.n; i++) {
        if (!used[i] && mat[v][i]) {
            for (int j = 0; j < H.n; j++) {
                mat[v][j] = false;
            }

            mat[v][i] = true;
            mapped_to[v] = i;
            used[i] = true;

            attempt(v + 1, mat);

            if (found) {
                return;
            }

            mapped_to[v] = -1;
            used[i] = false;
            mat = temp;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    for (cin >> N; N != 0; cin >> N) {
        G.read(N);
        H.read(N);
        matrix mapping(G.n, row(H.n, true));
        memset(used, false, sizeof used);
        memset(mapped_to, 255, sizeof mapped_to);
        found = false;

        assert(G.n == H.n);

        for (int i = 0; i < G.n; i++) {
            for (int j = 0; j < H.n; j++) {
                if (G.in_degree[i] != H.in_degree[j] ||
                    G.out_degree[i] != H.out_degree[j]) {
                    mapping[i][j] = false;
                }
            }
        }

        attempt(0, mapping);

        G.clear();
        H.clear();
    }
    
    return 0;
}
