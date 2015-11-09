#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;

struct Ip {
    int a, b, c, d;

    Ip() : a(0), b(0), c(0), d(0) { }

    bool operator < (const Ip& ip) const {
        if (a != ip.a) {
            return a < ip.a;
        }

        if (b != ip.b) {
            return b < ip.b;
        }

        if (c != ip.c) {
            return c < ip.c;
        }

        return d < ip.d;
    }
};

struct Compare {
    bool operator () (const pair <int, int>& lhs, const pair <int, int>& rhs) const {
        if (lhs.first != rhs.first) {
            return lhs.first > rhs.first;
        }

        return lhs.second < rhs.second;
    }
};

map <Ip, int> last_moment;
map <int, int> score;
set <pair <int, int>, Compare> Set;
char command[10];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    for (int i = 1; i < 100011; i++) {
        Set.insert(make_pair(0, i));
    }

    while (scanf("%s\n", command) == 1) {
        if (strcmp(command, "EXIT") == 0) {
            puts("OK");
            break;
        }

        if (strcmp(command, "VOTE") == 0) {
            Ip ip;
            int id, delta, moment;

            scanf("%d.%d.%d.%d %d %d %d\n", &ip.a, &ip.b, &ip.c, &ip.d, &id, &delta, &moment);

            moment += 600;
            if (moment - last_moment[ip] >= 600) {
                last_moment[ip] = moment;
                Set.erase(make_pair(score[id], id));
                score[id] += delta;
                Set.insert(make_pair(score[id], id));
            }

            printf("%d\n", score[id]);
        } else if (strcmp(command, "GET") == 0) {
            pair <int, int> ans = *Set.begin();
            Set.erase(Set.begin());
            score[ans.second] = -1;
            Set.insert(make_pair(score[ans.second], ans.second));

            printf("%d %d\n", ans.second, ans.first);
        }


        /*
        for (auto it: Set) {
            printf("{%d, %d}, ", it.first, it.second);
        }
        puts("");
        */
    }

    return 0;
}
