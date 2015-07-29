#ifndef WSO13_INDEX_UTILS_090519
#define WSO13_INDEX_UTILS_090519

#include "cassert"
#include "Common\DataTypes.h"

static inline int IndexToSlot(int type, int index) {
    switch (type) {
        case 1: return index;
        case 2: return MAX_FACTORY_COUNT + index;
        case 3: return MAX_FACTORY_COUNT + MAX_ROBOT_COUNT + index;
        default: assert(0); return -1;
    }
}
static inline int SlotToIndex(int slot) {
    if (slot < MAX_FACTORY_COUNT) return slot;
    slot -= MAX_FACTORY_COUNT;
    if (slot < MAX_ROBOT_COUNT) return slot;
    slot -= MAX_ROBOT_COUNT;
    if (slot < MAX_PROJECTILE_COUNT) return slot;
    assert(0);
    return -1;
}
static inline int SlotToType(int slot) {
    if (slot < MAX_FACTORY_COUNT) return 1;
    slot -= MAX_FACTORY_COUNT;
    if (slot < MAX_ROBOT_COUNT) return 2;
    slot -= MAX_ROBOT_COUNT;
    if (slot < MAX_PROJECTILE_COUNT) return 3;
    assert(0);
    return -1;
}

#endif
