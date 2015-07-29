#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n,t1,t2,k;

int absm(int a)
{
	if (a<0) return -a;
	return a;
}

int main()
{
	freopen("input.txt","r",stdin);
	cin>>n>>t1>>t2;
	cin>>k;
	int st=1;
	int timer=0;
	vector <int> a;
	for (int i=0;i<k;i++)
		{
			int x,t,m=0;
			cin>>t>>x;
			if (t>timer)
			timer=t;
			else m+=timer-t;
			m+=t1*min(absm(st-x),absm(n-x+st)%n);
			m+=t2;
			a.push_back(m);
			if (t<timer) timer+=m-timer+t;
			else timer+=m;
			st=x;
		}
	double rez=0;
	for (int i=0;i<k;i++)
		rez+=double(a[i]);
	rez=rez/k;
	printf("%.3lf",rez);
	return 0;
}
