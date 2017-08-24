/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

static vector <tuple <int, int> > test = {
    make_tuple(97, -1),
    make_tuple(58, 5),
    make_tuple(16, 2),
    make_tuple(81, 1),
    make_tuple(79, 4)
};

int rem = 2000;
tuple <int, int> ask(int pos) {
    rem--;
#ifdef ONLINE_JUDGE
    cout << "? " << pos << endl << flush;
    int val, nxt;
    cin >> val >> nxt;
    return make_tuple(val, nxt);
#else
    return test[pos - 1];
#endif
}

void ans(int num) {
    cout << "! " << num << endl;
    exit(0);
}

int main() {
    srand(time(NULL));

    int n, start, x;
    cin >> n >> start >> x;

    vector <int> idx;
    for (int i = 1; i <= n; i++) {
        idx.push_back(i);
    }

    random_shuffle(all(idx));
    for (int& num : idx) {
        if (num == start) {
            swap(idx[0], num);
            break;
        }
    }

    vector <tuple <int, int, int> > data;
    for (int i = 0; i < min(1000, n); i++) {
        int pos = idx[i];
        int val, nxt;
        tie(val, nxt) = ask(pos);
        data.emplace_back(val, pos, nxt);
    }

    sort(all(data));

    if (get<0>(data[0]) >= x) {
        ans(get<0>(data[0]));
    }

    auto cur = data[0];
    for (size_t j = 1; j < data.size(); j++) {
        if (get<0>(data[j]) < x) {
            cur = data[j];
        }
    }

    while (get<2>(cur) != -1 && rem > 0) {
        cerr << "Val " << get<0>(cur) << ' ' << " pos: " << get<1>(cur) << " nxt: " << get<2>(cur) << endl;
        int val, nxt;
        tie(val, nxt) = ask(get<2>(cur));
        if (val >= x) {
            ans(val);
        }
        cur = make_tuple(val, get<2>(cur), nxt);
    }

    ans(-1);
    
    return 0;
}
