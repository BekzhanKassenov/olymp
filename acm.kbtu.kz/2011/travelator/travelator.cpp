#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int x,y;
int x1,y3;
int x2,y2,v,w;

double minim(double a,double b)
{
if (a>b) return a;
return b;
}

double rasst(int q,int w,int e,int r)
{
return (sqrt(double)((e-q)*(e-q)+(r-w)*(r-w)));
}

double btr()
{
  double tr=(rasst(x1,y1,x2,y2))/(double(w));
  double v1=(rasst(x1,y1,0,0)+rasst(x,y,x2,y2))/(double)v;
  double v2=(rasst(x2,y2,0,0)+rasst(x,x1,y,y1))/(double)v;
  return (minim(v1,v2)+tr);
}

bool test()
{
int a=y;
int b=-x;
int a1=y2-y1;
int b1=x1-x2;
int c=x2*y2-y2*x1;
bool k=((a*x1+b*y1)*(a*x2+b*y2)<0);
k=k && ((a*x+b*y+c)*c<0);
return k;
}

double bl()
{
  if (test)
  {
	double v1=(rasst(x1,y1,0,0)+rasst(x,y,x1,y1))/double(v);
	double v2=(rasst(x2,y2,0,0)+rasst(x,y,x2,y2))/double(v);
  	return minim(v1,v2);
  }
   else return rasst(x,y,0,0)/v;
}

bool trv()
{
bool v1=(x1==0) && (y1==0) && (x2==x) && (y2==y);
bool v2=(x2==0) && (y2==0) && (x1==x) && (y1==y);
}


int main()
{
 cin>>x>>y;
 cin>>x1>>y1;
 cin>>x2>>y3>>v>>w;
 if ((v==0) && (w==0))
    {
    cout<<0;
    return 0;
    }
 if (v==0) 
     if (trv && w!=0) 
	{
	   cout<<btr;
	   return 0;
	}
 if (w==0)
     if (v!=0)       
	{
	   cout<<bl
	   return 0;
	}
  cout<<minim(btr,bl);
  return 0;
}

