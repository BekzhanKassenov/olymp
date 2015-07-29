#include <iostream>
#include <cstdio>
#include <set>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string a,b;
	cin>>a>>b;
	int lena=a.length(), lenb=b.length();
	string k[1000];
	set <string> z;
	for (int i=0;i<=lena-lenb;i++)
		{
			k[i]=(a.substr(i,lenb));
			//cout<<k[i]<<endl;
		}
	int ans=0;
	for (int i=0;i<lenb;i++)
		{
			string n=b.substr(i,lenb-i)+b.substr(0,i);
			if (z.find(n)==z.end())
				{
					z.insert(n);	
					for (int i=0;i<=(lena-lenb);i++)
					if (k[i]==n) ans++;
		      }
	   }
   cout<<ans;
   return 0;
}
