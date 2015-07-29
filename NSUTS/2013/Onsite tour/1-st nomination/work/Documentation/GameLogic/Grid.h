#ifndef WSO13_GRID_670360
#define WSO13_GRID_670360

#include "Common\Point.h"
#include <vector>

//Enable this only if there are some doubts about grid correctness
//#define CHECK_WITH_DULL_ALGORITHM

class Grid {
    struct Item {
        Point pos;
        double rad;
        int tag;
        inline Item() : tag(-1) {}
        inline Item(const Point &_pos, double _rad, int _tag) : pos(_pos), rad(_rad), tag(_tag) {}
        inline bool operator< (const Item &other) const { return tag < other.tag; }
        inline bool operator== (const Item &other) const { return tag == other.tag; }
    };
    struct Entry {
        Item item;
        int next;
    };

    double scalingCoeff;
    int size;
    std::vector<Entry> entries;
    std::vector<int> cells;
    std::vector<int> alloc;

#ifdef CHECK_WITH_DULL_ALGORITHM
    std::vector<Item> items;
#endif

    int &GetCell(int x, int y);
    template<class Callback> void MarchCircle(Point position, double radius, Callback &callback);
    int AllocEntry();
    int FreeEntry(int idx);

    class InsertCallback;
    class EraseCallback;
    class GatherCallback;
    class ClearCallback;

    static std::vector<int> FilterItems(const std::vector<Item> &itemsVector, const Point &pos, double rad);

public:
    Grid(double approxSize);

    void Insert(int tag, Point position, double radius);
    void Erase(int tag, Point position, double radius);
    std::vector<int> GetCollidingTags(Point position, double radius) const;
    void Clear();

};

#endif

