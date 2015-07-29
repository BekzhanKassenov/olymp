#ifndef WSO13_POINT_907356
#define WSO13_POINT_907356

#include "Common\DataTypes.h"
#include <cmath>
#include <algorithm>
#include <cfloat>

static const double PI = 3.1415926535897932384626433832795;
static const double EPS = 1e-10;

struct Point {
    union {
		double crd[2];
		struct { double x; double y; };
	};

    inline Point() : x(0.0), y(0.0) {}
    inline Point(double _x, double _y) : x(_x), y(_y) {}

	inline double &operator[] (int i) { return crd[i]; }
	inline const double &operator[] (int i) const { return crd[i]; }

    inline Point operator- () const { return Point(-x, -y); }
    inline double operator! () const { return sqrt(x*x + y*y); }

    inline double operator^ (const Point &b) const {
		return x*b.x + y*b.y;
	}
	inline double operator% (const Point &b) const {
		return x*b.y - y*b.x;
	}


    inline operator CoordsXY() const {
        CoordsXY res;
        res.x = x;
        res.y = y;
        return res;
    }
    inline Point(const CoordsXY &xy) {
        x = xy.x;
        y = xy.y;
    }
};

#define DEF_CWOP_PNT(SYMBOL) \
    inline Point &operator SYMBOL= (Point &a, const Point &b) {\
        a.x SYMBOL= b.x;\
        a.y SYMBOL= b.y;\
        return a;\
    }\
    inline Point operator SYMBOL (const Point &a, const Point &b) {\
        Point res(a);\
        res SYMBOL= b;\
        return res;\
    }
#define DEF_CWOP_SC(SYMBOL) \
    inline Point &operator SYMBOL= (Point &a, double b) {\
        a.x SYMBOL= b;\
        a.y SYMBOL= b;\
        return a;\
    }\
    inline Point operator SYMBOL (const Point &a, double b) {\
        Point res(a);\
        res SYMBOL= b;\
        return res;\
    }\
    inline Point operator SYMBOL (double a, const Point &b) {\
        Point res(b);\
        res SYMBOL= a;\
        return res;\
    }

    DEF_CWOP_PNT(+);
    DEF_CWOP_PNT(-);
    DEF_CWOP_PNT(/);
    DEF_CWOP_PNT(*);
    DEF_CWOP_SC(/);
    DEF_CWOP_SC(*);

#undef DEF_CWOP_PNT
#undef DEF_CWOP_SC


namespace std {
	inline Point min(const Point &a, const Point &b) {
        return Point(min(a.x, b.x), min(a.y, b.y));
	}
    inline Point max(const Point &a, const Point &b) {
        return Point(max(a.x, b.x), max(a.y, b.y));
	}
};

inline Point Polar(double angle) { return Point(cos(angle), sin(angle)); }

inline bool IsFinite(double val) {
    return _finite(val) && fabs(val) < 1e+100;
}
inline bool IsFinite(const Point &p) {
    return IsFinite(p.x) && IsFinite(p.y);
}

inline Point Normalize(const Point &p) {
    double magn = !p;
    if (magn < EPS)
        return Point();
    else
        return p / magn;
}

inline Point LimitNorm(const Point &p, double maxNorm) {
    double magn = !p;
    if (magn < maxNorm)
        return p;
    else
        return p * (maxNorm / magn);
}

inline Point LimitInRect(const Point &p, const Point &bmin, const Point &bmax) {
    Point res = std::max(p, bmin);
    res = std::min(res, bmax);
    return res;
}

inline bool IsInRect(const Point &p, const Point &bmin, const Point &bmax) {
    return p.x >= bmin.x && p.y >= bmin.y && p.x <= bmax.x && p.y <= bmax.y;
}

inline double dRandom(double maxVal = 1.0) {
    //Note: MSVC only
    return maxVal * ((rand() << 15) ^ rand()) / double(1<<30);
}

#endif
