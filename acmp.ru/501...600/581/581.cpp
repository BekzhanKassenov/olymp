#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

double a,b,c;

bool test(double x,double y,double r)
{
    if (abs(a*x+b*y+c)/(sqrt(a*a+b*b))<=r) return true;
    return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    vector <int> ans;
    double x1,x2,y1,y2;
    cin>>n;
    cin>>x1>>y1>>x2>>y2;
    a=y2-y1;
    b=x1-x2;
    c=x2*y1-x1*y2;
   double r;    
    for (int i=0;i<n;i++)
        {
            cin>>x1>>y1>>r;
            if (test(x1,y1,r)) 
                ans.push_back(i);
        }
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]+1<<" ";
    return 0;
}