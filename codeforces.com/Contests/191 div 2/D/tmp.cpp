/* Miaki-Miha Solved On 4th July,2013 */
#include<cstdio>
#include<sstream>
#include <iostream>
#define Wsput putchar(' ')
#define Lnput putchar('\n')

using namespace std;

const int Mx[]={1,0,-1,0},My[]={0,1,0,-1};

inline void Iget(int &x){
    static char ch; x=0;
    while (((ch=getchar())<'0')||(ch>'9'));
    do{x=x*10+ch-'0';}while (((ch=getchar())>='0')&&(ch<='9'));
}

inline void Iput(int x){
    static char s[20],*p; p=s;
    do{*(++p)=x%10+'0',x/=10;}while (x);
    while (p!=s) putchar(*(p--));
}

int n,m,tot,head,tail;
char map[501][501];
struct Node{int p,x,y;Node(int p=0,int x=0,int y=0):p(p),x(x),y(y){}} q[250001];
stringstream ss;
inline void Inmap(int x,int y){
    if ((x<0)||(x>=n)||(y<0)||(y>=m)||(map[x][y]^'.')) return;
    q[++tail]=Node(2,x,y),map[x][y]='#';
}

inline void Make(char c, int x, int y) {
	ss << c << ' ' << x << ' ' << y << endl;
	tot++;
}

void Search(int sx,int sy){
    head=1,tail=0;
    for(Inmap(sx,sy);head<=tail;++head)
        for(int i=0;i<4;++i) Inmap(q[head].x+Mx[i],q[head].y+My[i]);
    for(int i=1;i<=tail;++i) Make('B', q[i].x + 1, q[i].y + 1);
    for(int i=tail;i>1;--i) Make('D', q[i].x + 1, q[i].y + 1), Make('R', q[i].x + 1, q[i].y + 1);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
    Iget(n),Iget(m);
    for(int i=0;i<n;++i) gets(map[i]);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) if (map[i][j]=='.') Search(i,j);
    Iput(tot),Lnput;
    cout << ss.str();
    return 0;
}