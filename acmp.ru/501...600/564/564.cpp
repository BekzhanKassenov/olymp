#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool check(double a, double b, double c) {
	return (a + b > c && a + c > b && b + c > a);
}

double S(double a, double b, double c) {
	double p = (a + b + c) / 2.0;

	return sqrt(p * (p - a) * (p - b) * (p - c)); 
}

double a[100];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int num1 = -1, num2 = -1, num3 = -1;

	double area = 0;

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (check(a[i], a[j], a[k]) && S(a[i], a[j], a[k]) > area) {
					area = S(a[i], a[j], a[k]);
					num1 = i;
					num2 = j;
					num3 = k;
				}
			}
		}
	}

	if (num1 != -1) {
		printf("%.14lf\n%d %d %d", area, num1 + 1, num2 + 1, num3 + 1);
	} else {
		cout << -1;
	}

	return 0;
}