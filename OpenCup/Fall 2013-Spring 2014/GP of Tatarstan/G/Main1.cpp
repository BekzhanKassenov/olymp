class SegmentTree {
    int *t, size;
    int *flag, *type;
public:
    SegmentTree() { }
    
    SegmentTree(int size) : size(size) {
        t = new int[4 * size];
        flag = new int[4 * size];
        type = new int [4 * size];
        
        memset(t, 0, 4 * size * sizeof (int));
        memset(flag, 0, 4 * size * sizeof (int));
        memset(type, 0, 4 * size * sizeof (int));
    }
    
    void assign(int l, int r, int val) {
        assign(1, 0, size - 1, l, r, val);
    }
    
    void add(int l, int r, int val) {
        add(1, 0, size - 1, l, r, val);
    }
    
    int get(int pos) {
        return get(1, 0, size - 1, pos);
    }
private:
    void push(int v, int l, int r) {
        if (l > r)
            return;
            
        if (l == r) {
            if (type[v] == 1)
                t[v] = flag[v];
            else if (type[v] == 2)
                t[v] += flag[v];
                
            type[v] = 0;
            flag[v] = 0;
            
            return;
        } 
        
        if (type[v << 1] == 0) {
            flag[v << 1] = flag[v];
            type[v << 1] = type[v];
        } else if (type[v << 1] == 1) {
            if (type[v] == 1)
                flag[v << 1] = flag[v];
            else
                flag[v << 1] += flag[v];
        } else {
            if (type[v] == 1)
        }
    }
    
    void assign(int v, int l, int r, int q_l, int q_r, int val) {
        
    }
};
