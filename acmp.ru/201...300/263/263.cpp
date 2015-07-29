#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,i,j;
	cin>>n>>i>>j;
	cout<<min(abs(max(i,j)-min(i,j)-1),abs(n-max(i,j)+min(i,j)-1));
	return 0;
}
