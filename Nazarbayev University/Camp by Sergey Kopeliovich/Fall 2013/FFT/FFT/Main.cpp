#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct my_complex {
private:
 	double x, y;

public:
    my_complex() : x(0), y(0) {}

    my_complex(int n) : x(double(n)), y(0) {}

    my_complex(double x) : x(x), y(0) {}

    my_complex(const my_complex& a) {
    	*this = a;
    }

    my_complex operator + (const my_complex& a) const {
    	return my_complex(x + a.x, y + a.y);
    }
    
    my_complex operator * (const my_complex& a) const {
 		return my_complex(x * a.x - y * a.y, y * a.x + x * a.y);
 	}
    void operator *= (const my_complex& a) {
 		double tx = x * a.x - y * a.y;
 		double ty = y * a.x + x * a.y;
 		x = tx, y = ty;
 	}

 	double& real() {
 		return x;
 	}

 	double& imag() {
 		return y;
 	}
};

const double PI = acos(-1.0);

