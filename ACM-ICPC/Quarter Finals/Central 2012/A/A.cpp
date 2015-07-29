/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}
void kill(){
	cout <<"NO";
	exit(0);
}
int main() {
   	int n;
	freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	string str;
	cin >> n>> str;
	bool cont = 1;
	char ch;
	ch = str[n-1];
	int pos, index = n-2;
	if (ch == 'C')
		{
			cout << "NO"; return 0;
		}
		if (ch == 'A')
			pos = 0;
			else
				pos = 1;
	while (index > -1){
		ch = str[index]; index--;
		if (cont){
		pos = pos%3;
			if (pos==0){
				if (ch == 'A')
					pos = pos*2;
					else if (ch == 'C')
						pos = pos*2+1;
						else if (ch == 'B')
							kill();
			}
			else if (pos==1){
				if (ch == 'C')
					pos = pos*2;
					else if (ch == 'B')
						pos = pos*2+1;
						else if (ch == 'A')
							kill();
			}
			else{
				if (ch == 'B')
					pos = pos*2;
					else if (ch == 'A')
						pos = pos*2+1;
						else if (ch == 'C')
							kill();
			} 

		}
		else {
			pos = pos%3;
				if (pos == 0){
					if (ch == 'A')
						pos = pos*2;
						else if (ch == 'B')
							pos = pos*2+1;
							else if (ch == 'C')
								kill();
				}
				else if (pos ==1){
					if (ch == 'B')
						pos = pos*2;
						else if (ch == 'C')
							pos = pos*2+1;
							else if (ch == 'A')
								kill();
				}
				else{
					if (ch == 'C')
						pos = pos*2;
						else if (ch == 'A')
							pos = pos*2+1;
							else if (ch == 'B')
								kill();
				}
		}

		cont = cont^1;	
	}
	cout << "YES";
	return 0;
}
