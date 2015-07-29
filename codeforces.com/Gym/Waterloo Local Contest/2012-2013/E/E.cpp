#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define all(x) (x).begin(), (x).end()

bool check_tr(double a, double b, double c) {
	return (a + b > c && a + c > b && b + c > a);
}

double area(double a, double b, double c) {
	double p = (a + b + c + .0) / 2;

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double a[6];
int pos[6];

bool check_edges() {
 	return (a[pos[0]] * a[pos[5]] < a[pos[1]] * a[pos[3]] + a[pos[2]] * a[pos[4]] && 
 			a[pos[1]] * a[pos[3]] < a[pos[0]] * a[pos[5]] + a[pos[2]] * a[pos[4]] && 
 			a[pos[2]] * a[pos[4]] < a[pos[0]] * a[pos[5]] + a[pos[1]] * a[pos[3]]);
}


bool check(double s1, double s2, double s3, double s4) {
	bool res = (s1 + s2 + s3 > s4 && s2 + s3 + s4 > s1 && s1 + s3 + s4 > s2 && s1 + s2 + s4 > s3);

	res |= check_edges();

	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	while (n --> 0) {
		for (int i = 0; i < 6; i++) {
			cin >> a[i];
			pos[i] = i;
		}

		bool ans = false;

		do {
		 	bool flag = true;
		 	flag &= check_tr(a[pos[0]], a[pos[1]], a[pos[2]]);
		 	flag &= check_tr(a[pos[0]], a[pos[3]], a[pos[4]]);
		 	flag &= check_tr(a[pos[1]], a[pos[4]], a[pos[5]]);
		 	flag &= check_tr(a[pos[2]], a[pos[3]], a[pos[5]]);
		 	
		 	if (flag) {
		 		double s1 = area(a[pos[0]], a[pos[1]], a[pos[2]]);
		 		double s2 = area(a[pos[0]], a[pos[3]], a[pos[4]]);
		 		double s3 = area(a[pos[1]], a[pos[4]], a[pos[5]]);
		 		double s4 = area(a[pos[2]], a[pos[3]], a[pos[5]]);

		 		flag |= check(s1, s2, s3, s4);
		 	}
		 	ans |= flag;
		} while (next_permutation(pos, pos + 6) && !ans);

		if (ans)
		 	cout << "YES" << endl;
		else
		 	cout << "NO" << endl;
	}

	return 0;
}
