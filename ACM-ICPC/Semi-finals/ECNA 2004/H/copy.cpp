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
    vector <string> word;
    vector <int> in_degree;
    vector <int> out_degree;
    map <string, int> num;

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

    vector <int> get_neighbourhood(size_t node_id) const {
        vector <int> result;
        for (int i = 0; i < n; i++) {
            if (adj[node_id][i]) {
                result.push_back(i);
            }
        }

        return result;
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
vector <bool> used;
vector <int> mapped_to;

bool refine(matrix& mat) {
    return true;
    bool result = true;
    bool refined = false;

    do {
        refined = false;
        
        for (int i = 0; i < H.n; i++) { // vertex in H
            bool has_one = false;

            for (int j = 0; j < G.n; j++) { // vertex in G
                if (mat[i][j]) {
                    has_one = true;
                    bool ok = true; // false if we should set mat[i][j] to 0
                    vector <int> neigh_i = H.get_neighbourhood(i);
                    vector <int> neigh_j = G.get_neighbourhood(j);
                    
                    for (size_t k = 0; k < neigh_i.size() && ok; k++) { // neighbour of i
                        bool found = false; 
                        for (size_t l = 0; l < neigh_j.size() && !found; l++) { // neighbour of j
                            found |= mat[neigh_i[k]][neigh_j[l]];
                        }
                        ok &= found;
                    }

                    if (!ok) {
                        mat[i][j] = 0;
                        refined = true;
                        result = true;
                    }
                }
            }

            if (!has_one) { // One row of mat is zero - mat cannot be embedding
                result = false;
                refined = false; // in order to break do {...} while loop;
                break;           // in order to break for (i) loop
            }
        }
    } while (refined);

    return result;
}

matrix transpose(const matrix& mat) {
    int n = mat.size();

    matrix result(n, row(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = mat[j][i];
        }
    }

    return result;
}

matrix operator * (const matrix& lhs, const matrix& rhs) {
    int n = lhs.size();

    matrix result(n, row(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] = result[i][j] || (lhs[i][k] && rhs[k][j]);
            }
        }
    }

    return result;
}

void attempt(int v, matrix& mat) {
    if (v == G.n) {
        for (int i = 0; i < G.n; i++) {
            for (int j = 0; j < H.n; j++) {
                cout << mat[i][j];
            }
            cout << endl;
        }
        cout << endl;
        if (H.adj == mat * G.adj * transpose(mat)) {
            for (int i = 0; i < G.n; i++) {
                cout << G.word[i] << '/' << H.word[mapped_to[i]] << endl;
            }
            cout << endl;

            found = true;
        }

        return;
    }

    matrix temp(mat);

    for (int i = 0; i < H.n; i++) {
        if (!used[i] && mat[v][i]) {
            mat[v].assign(H.n, false);
            mat[v][i] = true;
            mapped_to[v] = i;
            used[i] = true;

            if (refine(mat)) {
                attempt(v + 1, mat);
            }

            if (found) {
                return;
            }

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
        used.assign(H.n, false);
        mapped_to.assign(G.n, 0);
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
