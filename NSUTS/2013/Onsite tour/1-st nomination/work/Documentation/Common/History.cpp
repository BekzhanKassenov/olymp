#include "Common\History.h"
#include "Common\DataTypes.h"
#include "Common\IndexUtils.h"
#include "Common\TimeMemoryLimits.h"
#include "Common\Utils.h"
#include <algorithm>

#include "Common\quicklz.h"
static const int QUICKLZ_COMPRESSION_MAX_SIZE_INCREASE = 400;
static const int QUICKLZ_COMPRESSED_BLOCK_HEADER = 9;
static const int MAX_FRAME_SIZE = (sizeof(WorldData) + QUICKLZ_COMPRESSION_MAX_SIZE_INCREASE) * 2;

char compressedBuffer[MAX_FRAME_SIZE];
char uncompressedBuffer[MAX_FRAME_SIZE];

HistoryWriter::HistoryWriter() {}
HistoryWriter::~HistoryWriter() {}
HistoryWriter &HistoryWriter::Get() {
    static HistoryWriter obj;
    return obj;
}

bool HistoryWriter::Init(const char *filename) {
    file = fopen(filename, "wb");
    if (!file)
        return false;

    state.reset(new qlz_state_compress());
    memset(state.get(), 0, sizeof(*state));

    writtenWorldBytes = 0;

    return true;
}

void HistoryWriter::WriteFrame(const WorldData *pWorld) {
    size_t res;
    if (pWorld->currentTime == 0) {
        //initial frame, write as a memory chunk
        res = qlz_compress(pWorld, compressedBuffer, sizeof(WorldData), state.get());
    }
    else {
        if (!IsUnlimitedMode() && writtenWorldBytes > HISTORY_SIZE_LIMIT_PER_CYCLE * pWorld->currentTime)
            return;     //skip frame
        //write living units only
        int unc = WriteAsKeyFrame(pWorld);
        res = qlz_compress(uncompressedBuffer, compressedBuffer, unc, state.get());
        /*res = unc;
        memcpy(compressedBuffer, uncompressedBuffer, unc);*/
        writtenWorldBytes += res;
    }

    fwrite(&pWorld->currentTime, sizeof(int), 1, file);
    fwrite(compressedBuffer, res, 1, file);
    fflush(file);
}

void HistoryWriter::Close() {
    fclose(file);
    state.reset();
}


HistoryReader::HistoryReader() {}
HistoryReader::~HistoryReader() {}
HistoryReader &HistoryReader::Get() {
    static HistoryReader obj;
    return obj;
}

bool HistoryReader::Init(const char *filename) {
    file = fopen(filename, "rb");
    if (!file)
        return false;

    state.reset(new qlz_state_decompress());
    memset(state.get(), 0, sizeof(*state));

    int pos = 0;
    while (1) {
        if (fseek(file, pos, SEEK_SET))
            break;
        static const int bytesToRead = sizeof(int) + QUICKLZ_COMPRESSED_BLOCK_HEADER;
        char buff[bytesToRead];
        if (!fread(buff, bytesToRead, 1, file))
            break;
        pos += sizeof(int);

        FrameInfo fi;
        fi.gameTime = *((int*)buff);
        fi.filePos = pos;
        fi.fileSize = qlz_size_compressed(buff + sizeof(int));
        fi.origSize = qlz_size_decompressed(buff + sizeof(int));
        frames.push_back(fi);

        pos += fi.fileSize;
    }

    currentWorld.reset(new WorldData());
    currentGameTime = -1;
    currentFrameIdx = 0;
    GetFrame(0);

    return true;
}

int HistoryReader::GetLength() {
    return frames.back().gameTime + 1;
}

const WorldData *HistoryReader::GetFrame(int gameTime) {
    if (gameTime == currentGameTime)
        return currentWorld.get();

    if (gameTime < 0 || gameTime >= GetLength())
        return 0;
    currentGameTime = gameTime;
    while (frames[currentFrameIdx].gameTime > gameTime) currentFrameIdx--;
    while (frames[currentFrameIdx].gameTime < gameTime) currentFrameIdx++;
    const FrameInfo &fi = frames[currentFrameIdx];

    fseek(file, fi.filePos, SEEK_SET);
    fread(compressedBuffer, fi.fileSize, 1, file);

    if (currentFrameIdx == 0) {
        //initial frame, memory chunk
        qlz_decompress(compressedBuffer, currentWorld.get(), state.get());
    }
    else {
        int size = qlz_decompress(compressedBuffer, uncompressedBuffer, state.get());
        ReadAsKeyFrame(currentWorld.get(), size);
    }
    currentWorld->currentTime = currentGameTime;

    return currentWorld.get();
}




static inline void Write(char *&ptr, const void *src, int bytes) {
    memcpy(ptr, src, bytes);
    ptr += bytes;
}
template<class T> static inline void Write(char *&ptr, const T &obj) {
    Write(ptr, &obj, sizeof(obj));
}

static inline void Read(const char *&ptr, void *dst, int bytes) {
    memcpy(dst, ptr, bytes);
    ptr += bytes;
}
template<class T> static inline void Read(const char *&ptr, T &obj) {
    Read(ptr, &obj, sizeof(obj));
}

int HistoryWriter::WriteAsKeyFrame(const WorldData *pWorld) {
    char *ptr = uncompressedBuffer;

    for (int i = 0; i < MAX_UNITS_COUNT; i++) {
        int type = SlotToType(i);
        int idx = SlotToIndex(i);

        const Unit *ent = 0;
        int sz = 0;
        if (type == 1) { ent = &pWorld->factories[idx];  sz = sizeof(Factory); }
        if (type == 2) { ent = &pWorld->robots[idx];  sz = sizeof(Robot); }
        if (type == 3) { ent = &pWorld->projectiles[idx];  sz = sizeof(Projectile); }
        if (!ent || ent->id < 0) continue;

        Write(ptr, i);
        Write(ptr, ent, sz);
    }

    return ptr - uncompressedBuffer;
}

void HistoryReader::ReadAsKeyFrame(WorldData *pWorld, int size) {
    const char *ptr = uncompressedBuffer;
    const char *pEnd = uncompressedBuffer + size;

    memset(pWorld->factories, -1, sizeof(pWorld->factories));
    memset(pWorld->robots, -1, sizeof(pWorld->robots));
    memset(pWorld->projectiles, -1, sizeof(pWorld->projectiles));

    while (ptr < pEnd) {
        int slot;
        Read(ptr, slot);
        int type = SlotToType(slot);
        int idx = SlotToIndex(slot);

        Unit *ent = 0;
        int sz = 0;
        if (type == 1) { ent = &pWorld->factories[idx];  sz = sizeof(Factory); }
        if (type == 2) { ent = &pWorld->robots[idx];  sz = sizeof(Robot); }
        if (type == 3) { ent = &pWorld->projectiles[idx];  sz = sizeof(Projectile); }
        assert(ent);

        Read(ptr, ent, sz);
    }

    assert(ptr == pEnd);
}
