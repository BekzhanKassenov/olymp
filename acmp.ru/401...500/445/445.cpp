#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <map>

using namespace std;

#define all(x) (x).begin(), (x).end()

pair <string, double> readRow() {
    string name;
    double num;
    cin >> name >> num;
    
    for (char& c: name) {
        c = tolower(c);
    }

    return {name, num};
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k1, k2;
    double d;

    cin >> n >> d;
    cin >> k1 >> k2;

    map <string, double> orders, oldPrice, newPrice;
    vector <string> input;
    for (int i = 0; i < n; i++) {
        auto order = readRow();
        orders.insert(order);
        input.push_back(order.first);
    }

    for (int i = 0; i < k1; i++) {
        oldPrice.insert(readRow());   
    }

    for (int i = 0; i < k2; i++) {
        newPrice.insert(readRow());
    }

    vector <pair<double, string> > impr;
    for (const auto& order: orders) {
        if (newPrice.count(order.first)) {
            double diff = (oldPrice[order.first] - newPrice[order.first]) / oldPrice[order.first];
            if (diff > 0) {
                impr.push_back({diff, order.first});
            }
        }
    }

    sort(all(impr));
    reverse(all(impr));

    map <string, double> ans;
    for (const auto& p: impr) {
        if (d < 0.000000001) {
            break;
        }
        const string& name = p.second;
        double amountFromNew = min(orders[name], d / oldPrice[name]);
        ans[name] = amountFromNew;
        d -= amountFromNew * oldPrice[name];
        //res += amountFromNew * (oldPrice[name] - newPrice[name]);
    }

    cout << fixed << setprecision(5);
    for (const string& name : input) {
        if (ans.count(name)) {
            cout << ans[name] << endl;
        } else {
            cout << 0.0 << endl;
        }
    }

    return 0;
}
