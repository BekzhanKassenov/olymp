#include "GameLogic\Grid.h"
#include <cassert>

static const double INSERT_EPS = FIELD_SIZE * 1e-8;
static const double GATHER_EPS = FIELD_SIZE * 1e-8;
static const double ERASE_EPS = FIELD_SIZE * 1e-7;
static const double CLEAR_EPS = FIELD_SIZE * 1e-7;

inline int &Grid::GetCell(int x, int y) { return cells[x * size + y]; }

inline int Grid::AllocEntry() {
    if (alloc.empty()) {
        alloc.push_back(entries.size());
        Entry ne;
        ne.next = entries.size();
        entries.push_back(ne);
    }
    int res = alloc.back();
    alloc.pop_back();
    return res;
}

inline int Grid::FreeEntry(int idx) {
    alloc.push_back(idx);
    int res = entries[idx].next;
    entries[idx].next = idx;
    entries[idx].item.tag = -1;
    return res;
}

template<class Callback> void Grid::MarchCircle(Point position, double radius, Callback &callback) {
    int box[2][2];
    for (int d = 0; d<2; d++) {
        double cmin = position[d] - radius;
        double cmax = position[d] + radius;
        //scale to grid cell coordinates
        cmin *= scalingCoeff;
        cmax *= scalingCoeff;
        //get indices
        int imin = int(floor(cmin));
        int imax = int( ceil(cmax));
        //cut outside of world
        if (imin < 0) imin = 0;
        if (imax < 1) imax = 1;
        if (imin > size-1) imin = size-1;
        if (imax > size) imax = size;
        //set index ranges
        box[d][0] = imin;
        box[d][1] = imax;
    }

    //maybe, it's better to draw exactly circle instead of its AABBox?...

    for (int i = box[0][0]; i < box[0][1]; i++)
        for (int j = box[1][0]; j < box[1][1]; j++)
            callback(GetCell(i, j));
}

class Grid::InsertCallback {
    Grid &grid;
    const Item &item;
public:
    InsertCallback(Grid &_grid, const Item &_item) : grid(_grid), item(_item) {}
    void operator() (int& listStart) {
        int idx = grid.AllocEntry();
        grid.entries[idx].item = item;
        grid.entries[idx].next = listStart;
        listStart = idx;
    }
};

class Grid::EraseCallback {
    Grid &grid;
    int tag;
public:
    EraseCallback(Grid &_grid, const Item &_item) : grid(_grid), tag(_item.tag) {}
    void operator() (int& listStart) {
        int *cptr = &listStart;
        while (*cptr >= 0) {
            Entry &ent = grid.entries[*cptr];
            if (ent.item.tag == tag)
                *cptr = grid.FreeEntry(*cptr);
            else
                cptr = &ent.next;
        }
    }
};

class Grid::GatherCallback {
    const Grid &grid;
    std::vector<Item> &out;
public:
    GatherCallback(const Grid &_grid, std::vector<Item>& res) : grid(_grid), out(res) {}
    void operator() (int listStart) {
        const Entry *pEntries = &grid.entries[0];
        for (int curr = listStart; curr >= 0; curr = pEntries[curr].next) {
            const Item &item = pEntries[curr].item;
            bool found = false;

            int k = out.size();
            const Item *arr = (k ? &out[0] : 0);
            for (int i = 0; i < k; i++)
                if (arr[i].tag == item.tag) {
                    found = true;
                    break;
                }

            if (!found)
                out.push_back(item);
        }
    }
};

class Grid::ClearCallback {
    Grid &grid;
public:
    ClearCallback(Grid &_grid) : grid(_grid) {}
    void operator() (int &listStart) {
        listStart = -1;
    }
};


Grid::Grid(double approxSize) {
    size = int(approxSize) + 1;
    cells.assign(size*size, -1);
    scalingCoeff = size / FIELD_SIZE;
}

void Grid::Insert(int tag, Point position, double radius) {
    Item item(position, radius, tag);
    MarchCircle(position, radius + INSERT_EPS, InsertCallback(*this, item));

#ifdef CHECK_WITH_DULL_ALGORITHM
    items.push_back(item);
#endif
}

void Grid::Erase(int tag, Point position, double radius) {
    Item item(position, radius, tag);
    MarchCircle(position, radius + ERASE_EPS, EraseCallback(*this, item));

#ifdef CHECK_WITH_DULL_ALGORITHM
    for (int i = 0; i<items.size(); i++)
        if (items[i].tag == tag) {
            items.erase(items.begin() + i);
            return;
        }
#endif
}

std::vector<int> Grid::FilterItems(const std::vector<Item> &itemsVector, const Point &pos, double rad)
{
    std::vector<int> res;

    for (int i = 0; i < itemsVector.size(); i++) {
        Point diff = itemsVector[i].pos - pos;
        double sqrDist = diff ^ diff;
        double sumRad = itemsVector[i].rad + rad;
        if (sqrDist <= sumRad * sumRad)
            res.push_back(itemsVector[i].tag);
    }

    return res;
}

std::vector<int> Grid::GetCollidingTags(Point position, double radius) const {
    //dump all items that potentially intersect
    static std::vector<Item> potInters;
    potInters.clear();
    const_cast<Grid*>(this)->MarchCircle(position, radius + GATHER_EPS, GatherCallback(*this, potInters));
    //filter items that really collide
    std::vector<int> fastRes = FilterItems(potInters, position, radius);

#ifdef CHECK_WITH_DULL_ALGORITHM
    std::vector<int> res = FilterItems(items, position, radius);
    std::sort(res.begin(), res.end());
    std::sort(fastRes.begin(), fastRes.end());
    if (res != fastRes) {
        __debugbreak();
        terminate();
    }
#endif

    return fastRes;
}

void Grid::Clear() {
    for (int i = 0; i<entries.size(); i++) {
        const Item &item = entries[i].item;
        if (item.tag < 0) continue;
        MarchCircle(item.pos, item.rad + CLEAR_EPS, ClearCallback(*this));
        FreeEntry(i);
    }

#ifdef CHECK_WITH_DULL_ALGORITHM
    items.clear();
#endif
}
