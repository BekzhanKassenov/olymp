#ifndef WSO13_ARRAY_ALLOCATOR_068189
#define WSO13_ARRAY_ALLOCATOR_068189

#include <cassert>

template<int MaxSize> class ArrayAllocator {
    int freeIndices[MaxSize];
    int freeCount;

public:
    ArrayAllocator() {
        for (int i = 0; i<MaxSize; i++)
            freeIndices[i] = MaxSize-1 - i;
        freeCount = MaxSize;
    }
    int Allocate() {
        if (freeCount == 0) return -1;
        return freeIndices[--freeCount];
    }
    void Deallocate(int idx) {
        assert(freeCount < MaxSize);
        freeIndices[freeCount++] = idx;
    }
};

#endif
