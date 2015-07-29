#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int nmb(char a)
{
	if (a=='0') return 1;
	if (a=='1') return 0;
	if (a=='2') return 0;
	if (a=='3') return 0;
	if (a=='4') return 0;
	if (a=='5') return 0;
	if (a=='6') return 1;
	if (a=='7') return 0;
	if (a=='8') return 2;
	if (a=='9') return 1;

}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	cin>>s;
	int ans=0;
	for (int i=0;i<s.length();i++)
		ans+=nmb(s[i]);
	cout<<ans;
	return 0;
}
