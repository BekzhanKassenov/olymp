#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","w",stdout);
	cout<<16000<<' '<<16000<<endl;
	for (int i=0;i<16000;i++)
		cout<<32000-i<<' ';
	cout<<endl;
	for (int i=0;i<16000;i++)
		cout<<32000-i<<' ';
	return 0;
}
