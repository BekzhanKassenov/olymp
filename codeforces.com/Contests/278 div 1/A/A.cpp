/****************************************
**     Solution by Bekzhan Kassenov    **
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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int h, a, d;
int hp_cost;

struct Person {
  	int hp;
  	int atk;
  	int def;

  	void read() {
  	 	scanf("%d%d%d", &hp, &atk, &def);
  	}

  	bool wins(const Person& p) const {
  	 	int diff = max(0, p.atk - def);
  	 	int pers_diff = max(0, atk - p.def);

  	 	if (pers_diff == 0) {
  	 		return false;
        }

  	 	if (diff == 0) {
            hp_cost = 0;
  	 		return true;
        }

  	 	//int num1 = (hp + diff - 1) / diff;
  	 	int num2 = (p.hp + pers_diff - 1) / pers_diff;

        hp_cost = max(0, (num2 * diff - hp + 1)) * h;

        return true;
  	}
};

Person yan, monster;
int ans = INF;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    yan.read();
    monster.read();

    scanf("%d%d%d", &h, &a, &d);
    
    for (int i = 0; i < 201; i++) {
        yan.atk += i;
        for (int j = 0; j < 201; j++) {
            yan.def += j;

            if (yan.wins(monster)) {
                ans = min(ans, i * a + j * d + hp_cost);
        //        cout << i << ' ' << j << ' ' << ans << endl;
            }

            yan.def -= j;
        }

        yan.atk -= i;
    }

    
    printf("%d\n", ans);
    
    return 0;
}
