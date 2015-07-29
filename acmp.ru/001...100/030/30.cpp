#include <iostream>
#include <cstdio>

using namespace std;

int a[10];
int h,m,s;

void calc_array(int n)
{
	a[n%10]++;
	if (n>=10)
		a[n/10]++;
	else a[0]++;
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	for (int i=0;i<10;i++)
		a[i]=0;	
	int h1,m1,s1;
	char c;
	cin>>h>>c>>m>>c>>s;
	cin>>h1>>c>>m1>>c>>s1;
	calc_array(h);
	calc_array(m);
	calc_array(s);
	while ((s!=s1) || (h!=h1) || (m!=m1))
		{
			s++;
			if (s==60)
				{
					s=0;
					m++;
				}
		   if (m==60)
		   	{
		   		m=0;
		   		h++;
		   	}
		   if (h==24)
		   	h=0;
		   calc_array(s);
		   calc_array(h);
		   calc_array(m);
		}
   for (int i=0;i<10;i++)
   	cout<<a[i]<<endl;
	return 0;
}
