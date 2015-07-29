#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	if (a*b==c)
	cout<<"YES";
	else cout<<"NO";
	return 0;
}
