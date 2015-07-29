#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","w",stdout);
	cout<<"200 200"<<endl;
	for (int i=0;i<200;i++)
		{
			for (int j=0;j<200;j++)
			cout<<"#";
			cout<<endl;
		}
}
