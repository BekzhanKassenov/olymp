#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector < vector < int > > a ;

int n , m;

int absm ( int a )
{	
	if ( a < 0 ) return -a;
	return a;
}

int bfs ( int x, int y )
{
	if ( a[x][y] == 1)
		return 0;
	int ans = 99998999;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if ( a[i][j] == 1)
				ans = min ( ans, absm ( x - i ) + absm ( y - j ) ); 
	return ans;
} 

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n >> m;
	a.resize ( n );
	for (int i = 0; i < n; i++)
		a[i].resize ( m ); 
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < m ; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << bfs ( i, j ) << ' ';
			cout << endl;
		}
	return 0;
}
