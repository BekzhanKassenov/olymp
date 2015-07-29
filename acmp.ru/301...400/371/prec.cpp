#include <iostream>
#include <cstdio>

using namespace std;

#define MP make_pair
#define F first
#define S second

pair <int, int> a[40] = {
MP(220, 284),
MP(1184, 1210),
MP(2620, 2924),
MP(5020, 5564),
MP(6232, 6368),
MP(10744, 10856),
MP(12285, 14595),
MP(17296, 18416),
MP(63020, 76084),
MP(66928, 66992),
MP(67095, 71145),
MP(69615, 87633),
MP(79750, 88730),
MP(100485, 124155),
MP(122265, 139815),
MP(122368, 123152),
MP(141664, 153176),
MP(142310, 168730),
MP(171856, 176336),
MP(176272, 180848),
MP(185368, 203432),
MP(196724, 202444),
MP(280540, 365084),
MP(308620, 389924),
MP(319550, 430402),
MP(356408, 399592),
MP(437456, 455344),
MP(469028, 486178),
MP(503056, 514736),
MP(522405, 525915),
MP(600392, 669688),
MP(609928, 686072),
MP(624184, 691256),
MP(635624, 712216),
MP(643336, 652664),
MP(667964, 783556),
MP(726104, 796696),
MP(802725, 863835),
MP(879712, 901424),
MP(898216, 980984)
};
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	bool flag = false;

	for (int i = 0; i < 40; i++) {
		if (a[i].F >= n && a[i].F <= m)
			if (a[i].S >= n && a[i].S <= m) {
				cout << a[i].F << ' ' << a[i].S << endl;
				flag = true;
		   	}
	}

	if (!flag)
		cout << "Absent\n";

	return 0;	
}
