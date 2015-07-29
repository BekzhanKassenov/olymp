#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

pair <double, int> a[4];

double TurnTime, Distance, Time, Velocity;

int TimeToTurn(int a, int b) {
    if (a > b)
        swap(a, b);

    if (b - a > 4 - (b - a))
        return (4 - (b - a)) * TurnTime;

    return (b - a) * TurnTime;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 4; i++) {
        scanf("%lf%d", &a[i].first, &a[i].second);
    }

    scanf("%lf%lf", &TurnTime, &Distance);

    for (int i = 0; i < 4; i++) {
        a[i].first += Distance / a[i].second;
        a[i].second = i;
    }

    sort(a, a + 4);

    double CurrentTime = a[0].first;

    for (int i = 1; i < 4; i++) {
        double ComingTime = CurrentTime + TimeToTurn(a[i - 1].second, a[i].second);

        if (a[i].first < ComingTime) {
            printf("%d\n", i);
            return 0;
        }

        CurrentTime = a[i].first;
    }

    puts("ALIVE");

    return 0;
}
