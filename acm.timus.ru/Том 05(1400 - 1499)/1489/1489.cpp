#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define y1 asdas

double a, b, c;

void get_coord(double x, double y, double& res_x, double& res_y, double& res_z) {
 	if (y >= b + c + b) {
 		res_x = x - c;
 		res_y = b;
 		res_z = y - (b + c + b); 
 		return;
 	}

 	if (y >= b + c && y <= b + c + b) {
 	 	if (x <= c) {
 	 		res_x = 0;
 	 		res_y = y - b - c;
 	 		res_z = c - x;
 	 		return;
 	 	}

 	 	if (x <= c + a) {
 	 	  	res_x = x - c;
 	 	  	res_y = y - b - c;
 	 	  	res_z = 0;
 	 	  	return;
 	 	}

 	 	res_x = a;
 	 	res_y = y - b - c;
 	 	res_z = x - a - c;
 	 	return;
 	}

 	if (y >= b && y <= b + c) {
 		res_x = x - c;
 		res_y = 0;
 		res_z = c - y + b;
 		return;
 	}

 	res_x = x - c;
 	res_y = b - y;
 	res_z = c;
}

double sqr(double x) {
	return x * x;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> a >> b >> c;

	double x, y, x1, y1;

	cin >> x >> y >> x1 >> y1;

	double xx = 0, yy = 0, zz = 0, xx1 = 0, yy1 = 0, zz1 = 0;

	get_coord(x, y, xx, yy, zz);
	get_coord(x1, y1, xx1, yy1, zz1);

	printf("%.10lf", sqrt(sqr(xx - xx1) + sqr(yy - yy1) + sqr(zz - zz1)));

	return 0;
}
