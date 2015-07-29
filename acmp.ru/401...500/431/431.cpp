#include <fstream>
#include <queue>

using namespace std;

#define P pair <int, int> 

int I = 10000, d[70][70], u[] = { 1,  2, 2, 1, -1, -2, -2, -1}, l[] = {-2, -1, 1, 2,  2,  1, -1, -2}, a = -1, w, e, r, n, i, j, x, y;

bool D[70][70];

bool z(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < n)
			return 1;
	return 0;
}

main()
{
	ifstream p("input.txt");
	ofstream o("output.txt");
	p >> n;
	char c;
	for (i = 0; i < n; i++)  
		for (j = 0; j < n; j++)
			{
				p >> c;
				if (c == '@')
					if (a == -1)
						a = i, w = j;
					else
						e = i, r = j, d[i][j] = I;
				if (c == '#')
					d[i][j] = -1;
				if (c == '.')
					d[i][j] = I;
			}
			 
	queue <P> q;
	q.push(make_pair(a, w));
	while (q.size())
		{
			P k = q.front();
			q.pop();
			for (i = 0; i < 8; i++)
				{
					x = k.first + u[i], y = k.second + l[i];
					if (z(x,y) & d[x][y] == I)
						d[x][y] = d[k.first][k.second] + 1, q.push(make_pair(x,y));
				}
		}
	
	if (d[e][r] == I)
		o << "Impossible", exit(0);
	
	D[a][w] = 1;
	while (e != a || r != w)
		{
			D[e][r] = 1;
			for (i = 0; i < 8; i++)
				{
					x = e + u[i];
					y = r + l[i];
					if (z(x, y) && d[x][y] == d[e][r] - 1)
						{e += u[i]; r += l[i]; break;}
			   }
		}

	for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				if (d[i][j] == -1)
					o << '#';
				else
					if (D[i][j])
						o << '@';
					else
						o << '.';
			o << endl;
		}
}
