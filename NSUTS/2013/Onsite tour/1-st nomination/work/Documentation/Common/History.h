#ifndef WSO13_HISTORY_673052
#define WSO13_HISTORY_673052

#include <memory>
#include <vector>

struct qlz_state_decompress;
struct qlz_state_compress;
struct WorldData;

class HistoryWriter {
    std::auto_ptr<qlz_state_compress> state;
    FILE *file;
    int writtenWorldBytes;

    int WriteAsKeyFrame(const WorldData *pWorld);
    HistoryWriter();
public:
    static HistoryWriter &Get();
    ~HistoryWriter();
    bool Init(const char *filename);
    void WriteFrame(const WorldData *pWorld);
    void Close();
};

class HistoryReader {
    std::auto_ptr<qlz_state_decompress> state;
    FILE *file;

    struct FrameInfo {
        int gameTime;
        int filePos;
        int fileSize;
        int origSize;
    };
    std::vector<FrameInfo> frames;

    int currentFrameIdx;
    int currentGameTime;
    std::auto_ptr<WorldData> currentWorld;
    
    void ReadAsKeyFrame(WorldData *pWorld, int size);
    HistoryReader();
public:
    static HistoryReader &Get();
    ~HistoryReader();
    bool Init(const char *filename);
    int GetLength();
    const WorldData *GetFrame(int gameTime);
};

#endif
