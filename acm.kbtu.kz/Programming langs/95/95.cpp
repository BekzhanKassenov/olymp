#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <int> a(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    int m;
    cin>>m;
    vector <set <int> > g(n);
    for (int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            g[x-1].insert(y-1);
            g[y-1].insert(x-1);
        }
   const int inf=9999999;
    vector <int> ans(n,inf);
    vector <bool> used(n, false);
    ans[0]=0;
   for (int i=0;i<n;i++)
       {
           int v=-1;
           for (int j=0;j<n;j++)
               if ((!used[j]) && (v==-1 || ans[v]>ans[j]))
                   v=j;
           if (ans[v]==inf)
               break;
           used[v]=true;
           for (int j=0;j<n;j++)
               if (g[v].find(j)!=g[v].end() && ans[j]>ans[v]+a[v])
                   ans[j]=ans[v]+a[v];    
       }
   if (ans[n-1]!=inf)
       cout<<ans[n-1];
   else 
       cout<<-1;
   return 0;    
}