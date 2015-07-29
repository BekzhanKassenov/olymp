#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

long long n=1;
long long sum=0;
char c;
long long ans=0;

long long sm(long long k)
{
    long long s=k;
    if (s<10) return s;
    long long as=0;
    while (s>0)
        {
            as+=s%10;
            s=s/10;
        }
    n++;
    return sm(as);
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    int len=s.length();
    int ans=0;
    if (len==1)
    	{
    		cout<<s[0]<<" "<<0;
    		return 0;
    	}
    for (int i=0;i<len;i++)
    	ans+=s[i]-48;
    ans=sm(ans);
    cout<<ans<<" "<<n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
