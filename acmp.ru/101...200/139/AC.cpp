#include <iostream>
#include <cstdio>

using namespace std;

const int c=1000000;
 
int i,j,l,k;
long a[10001][3];
int n,m, d[2005];
bool FLAG;
bool q[10001],q2[10005];
bool u[2005], u2[2005];

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    cin>>n>>m;
    
    for (i = 0; i < m; i++) {  
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        a[i][2]*=-1;
    }
 
    for(i=1;i<=n;i++)
        d[i]=c;
    
    d[1]=0;
    u[1]=true;
    
    for(k=1;k<n;k++)
        for(j=0;j<m;j++){
            if(d[a[j][1]]>d[a[j][0]]+a[j][2]&&d[a[j][0]]!=c)
               d[a[j][1]]=d[a[j][0]]+a[j][2];

            if(u[a[j][0]]) {
                q[j] = u[a[j][1]] = 1;
            }
        }
 
 
    if(d[n] > c/2) { 
        cout<<":(";
        return 0;
    }
 
    u2[n]=1;

    for(k=1;k<=n;k++)
        for(j=0;j<m;j++){
            if(d[a[j][1]]>d[a[j][0]]+a[j][2]&&d[a[j][0]]!=c)
            {
                d[a[j][1]]=d[a[j][0]]+a[j][2];
                
                if (q[j] && q2[j]) // !!!
                    FLAG = 1;
            }
            if(u2[a[j][1]]){q2[j]=1;u2[a[j][0]]=1;}
        }
 
    
    for (int i = 0; i < m; i++) {
        cerr << q[i] << ' ' << q2[i] << endl;
    }
    if(FLAG)cout<<":)";
    else cout<<d[n]*-1;
    return 0;
}