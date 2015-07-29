#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	vector <int> a(3),b(3);
	cin>>a[0]>>a[1]>>a[2];
	cin>>b[0]>>b[1]>>b[2];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if ((a[0]==b[0] && b[1]==a[1]) && b[2]==a[2])
		{
			cout<<"Boxes are equal";
			return 0;
		}
	if ((a[0]>=b[0] && a[1]>=b[1]) && a[2]>=b[2])
	   {
			cout<<"The first box is larger than the second one";
			return 0;
		}
	if ((a[0]<=b[0] && a[1]<=b[1]) && a[2]<=b[2])
	   {
			cout<<"The first box is smaller than the second one";
			return 0;
		}
	cout<<"Boxes are incomparable";
	return 0;
}
