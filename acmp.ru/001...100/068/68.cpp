#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	int n;
	cin>>s>>n;
	if (s=="School" && n%2==0) cout<<"NO";
	else cout<<"YES";
	return 0;
}
