#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define all(x) (x).begin(), (x).end()

map <string, pair <int, int> > Map;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    string temp, name;
    int cost;

    for (int i = 0; i < 6; i++) {
        cin >> temp >> name >> cost;
        if (!Map.count(name)) {
            Map[name] = make_pair(1, cost);
        } else {
            Map[name].first++;
            Map[name].second = min(Map[name].second, cost);
        }
    }

    vector <tuple <int, int, string> > vec;
    for (const auto& it: Map) {
        vec.emplace_back(it.second.first, it.second.second, it.first);
    }

    sort(all(vec), [] (const tuple <int, int, string>& a, const tuple <int, int, string>& b) {
        if (get<0>(a) != get<0>(b)) {
            return get<0>(a) > get<0>(b);
        }

        return get<1>(a) < get<1>(b);
    });

    cout << get<2>(vec[0]) << endl;

    return 0;
}
