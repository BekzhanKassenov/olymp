#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_GRAPH_SIZE = 2000;
const int MAX_QUERY_SIZE = 1000;

void prepare() {
    freopen("in", "w", stdout);
    
    srand(time(NULL));
}

int last_vertex_num;

void build_graph(int v, int cnt) {
    if (cnt == 0)
        return;
        
    while (cnt) {
        int size = rand() % cnt + 1;
        
        cout << v + 1 << ' ' << ++last_vertex_num + 1 << endl;
        
        build_graph(last_vertex_num, size - 1);
        
        cnt -= size;
    }
}

int generate_graph() {
    int n = rand() % MAX_GRAPH_SIZE + 1;
    
    cout << n << endl;
    
    build_graph(0, n - 1);
    
    return n;
}

void generate_queries(int graph_size) {
    int m = rand() % MAX_QUERY_SIZE + 1;
    
    cout << m << endl;
    
    for (int i = 0; i < m; i++) {
        if (rand() & 1) {
            cout << "I " << rand() % graph_size + 1 << ' ' << rand() << endl;
        } else {
            cout << "G " << rand() % graph_size + 1 << ' ' << rand() % graph_size + 1 << endl;
        }
    }
}

int main() {
    prepare();
    
    int graph_size = generate_graph();
    
    generate_queries(graph_size);
    
    return 0;
}
