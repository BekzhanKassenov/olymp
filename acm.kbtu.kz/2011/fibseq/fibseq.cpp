#include <iostream>
#include <cstdio>

using namespace std;

const int mx=70;

long long fib[mx];

void mfibseq()
{
	fib[0]=1;
	fib[1]=1;
	for (int i=2; i<mx;i++)
		fib[i]=fib[i-1]+fib[i-2];
}

long long nmb_of_bytes(long long n)
{
	for (int i=1;i<mx;i++)
		if (n<fib[i]) return ((long long) (i-1));
}

bool one_end(long long n)
{
	if (n==1) return true;
	if (n==0) return false;
	return one_end(n-fib[nmb_of_bytes(n)]);
}


/*int main()
{
	freopen("fibseq.in","r",stdin);
	freopen("fibseq.out","w",stdout);
	long long n;
	cin>>n;
	if (n==1) 
		{
			cout<<0;
			return 0;
		}
	if (n==2) 
		{
			cout<<1;
			return 0;
		}
	mfibseq();
	long long len=3;
	int ans=1;
	long long i=3;
	while (len < n)
		{
			len+=nmb_of_bytes(i);
			if ((one_end(i)) && (len<n-1)) ans++;
			i++;
		}
	cout<<ans;
	return 0;
}*/

int main()
{
	freopen("fibseq.out","w",stdout);
	mfibseq();
	int i1=1;
	for (int i=1;i<=500;i++)
		if (one_end(i)) 
			{
				cout<<endl<<i<<" "<<i-i1<<endl;
				i1=i;
			}
	return 0;
}
