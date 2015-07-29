#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector <vector <int> > v;

void writeln(v a)
{
	for (int i=0;i<8;i++)
		{
			for (int j=0;j<8;j++)
				cout<<a[i][j]<<' ';
			cout<<endl;
		}
}

bool test(int a, int b)
{
	if (a>=0 && a<8)
		if (b>=0 && b<8)
			return true;
	return false;
}

v bfs(int a,int b)
{
	v ans(8, vector <int> (8,9999999));
	ans[a][b]=0;
	for (int k=0;k<64;k++)
		{
			for (int i=0;i<8;i++)
				for (int j=0;j<8;j++)
						{
							if (test(i-2,j+1))
								ans[i-2][j+1]=min(ans[i-2][j+1],ans[i][j]+1);
							
							if (test(i-1,j+2))
								ans[i-1][j+2]=min(ans[i-1][j+2],ans[i][j]+1);
							
							if (test(i-1,j-2))
								ans[i-1][j-2]=min(ans[i-1][j-2],ans[i][j]+1);
							
							if (test(i-2,j-1))
								ans[i-2][j-1]=min(ans[i-2][j-1],ans[i][j]+1);
							
							if (test(i+2,j+1))
								ans[i+2][j+1]=min(ans[i+2][j+1],ans[i][j]+1);
							
							if (test(i+1,j+2))
								ans[i+1][j+2]=min(ans[i+1][j+2],ans[i][j]+1);
							
							if (test(i+1,j-2))
								ans[i+1][j-2]=min(ans[i+1][j-2],ans[i][j]+1);
							
							if (test(i+2,j-1))
								ans[i+2][j-1]=min(ans[i+2][j-1],ans[i][j]+1);
						}
		}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char a,b,c,d;
	int ai,bi,ci,di;
	cin>>a>>b>>c>>d;
	ai=(a-'a');
	bi=(b-'0')-1;
	ci=(c-'a');
	di=(d-'0')-1;
	v a1,a2;
	a1=bfs(ai,bi);
	a2=bfs(ci,di);
	/*writeln(a1);
	cout<<endl;
	writeln(a2);*/
	int ans=99999;
	for (int i=0;i<8;i++)
		for (int j=0;j<9;j++)
			if (a1[i][j]==a2[i][j])
				ans=min(ans,a1[i][j]);
	if (ans!=99999)
	cout<<ans;
	else cout<<-1;
	return 0;
}
