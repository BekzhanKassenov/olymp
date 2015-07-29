#include <iostream>
#include <cstdio>

using namespace std;

string getsstr()
{
	string c,s;
	cin>>s;
	getline(cin,c);
	string k=s+c;
	return k;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("outpu.txt","w",stdout);
	int n;
	string s;
	cin>>n;
	cout<<getsstr();
	cin>>n;
	cout<<n;
	return 0;
}
