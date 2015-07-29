#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double EPS = 1e-4;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
   	#endif

   	double a, b;

   	cin >> a >> b;
   	
   	if (b <= a / 2) {
   		printf("%.3lf", M_PI * b * b);
   		return 0;
   	}

   	if (b >= a / sqrt(2)) {
   		printf("%.3lf", a * a);
   		return 0;
   	}

   	double S = b * b * acos((a * a) / (2 * b * b) - 1) / 2 - a * sqrt(b * b - (a * a) / 4) / 2;

   	printf("%.3lf", M_PI * b * b - 4 * S); 

  	return 0;
}
