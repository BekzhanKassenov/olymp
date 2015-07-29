#include <string>
#include <fstream>

typedef std::string w;

w q(w a,w b)
{
    int y=a.size(), t=b.size();
    if (y==t)
            if (a>b) return a;
            else return b;
    if (y<t) return b;
    return a;
}

int main()
{
    std::ifstream i("input.txt");
    std::ofstream o("output.txt");
    w a,b,c;
    i>>a>>b>>c;
    o<<q(q(a,b),c);
    return 0;
}
