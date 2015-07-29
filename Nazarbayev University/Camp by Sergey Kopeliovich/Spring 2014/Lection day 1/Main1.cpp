// Offline scanline
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

const int maxn = 200010;

double curX;

enum {BEGIN, QUERY, END};

struct Segment {
    int x, y, _x, _y;
    int num;
    
    double getY() const {
       return (curX - x) * (_y - y) / (_x - x) + y; 
    }
    
    bool operator < (const Segment & seg) const {
        if (getY() < seg.getY())
            return true;
            
        return false;
    }
};

struct Event {
    int type, num;
    int x, y;
    
    Event() { }
    
    Event(int type, int num, int x, int y) : type(type), num(num), x(x), y(y) { }
    
    bool operator < (const Event& ev) const {
        if (x != ev.x)
            return x < ev.x;
            
        if (type != ev.type)
            return type < ev.type;
            
        return num < ev.num;
    }
};

int last = 0;
Event event[maxn];
set <Segment> Set;
Segment segment[maxn];
int n, m, x[maxn];
double ans[maxn];

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &segment[i].x, &segment[i].y, &segment[i]._x, &segment[i]._y);
        if (segment[i].x > segment[i]._x) {
            swap(segment[i].x, segment[i]._x);
            swap(segment[i].y, segment[i]._y);
        }
        
        event[last++] = Event(BEGIN, i, segment[i].x,  segment[i].y);
        event[last++] = Event(END,   i, segment[i]._x, segment[i]._y);
    }
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d", x + i);
        
        event[last++] = Event(QUERY, i, x[i], -1);
    }
    
    sort(event, event + last);
    
    for (int i = 0; i < last; i++) {
        curX = event[i].x;  
        if (event[i].type == BEGIN) {
            Set.insert(segment[event[i].num]);
        } else if (event[i].type == END) {
            Set.erase(segment[event[i].num]);
        } else {
            ans[event[i].num] = Set.begin() -> getY(); 
        }
    }
    
    for (int i = 0; i < m; i++)
        printf("%.5lf\n", ans[i]);
    
    return 0;
}
