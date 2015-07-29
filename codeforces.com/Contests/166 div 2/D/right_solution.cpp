#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

typedef struct Vertex* PVertex;

struct Vertex
{
	bool leaf;

	PVertex next[26];

	Vertex(bool l)
		{
			leaf = l;

			for (int i = 0; i < 26; i++)
				next[i] = NULL;
		}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio(false);

	string s;
	
	cin >> s;

	bool good[26];

	int k;

	char c;

	string tmp;

	cin >> tmp;

	for (int i = 0; i < 26; i++)
		good[i] = tmp[i] - '0';

	cin >> k;

	int n = s.size();

	int ans = 0;

	PVertex root = new Vertex(true);

	for (int i = 0; i < n; i++)
		{
			PVertex current = root;

			int cnt = 0;

			for (int j = i; j < n; j++)
				{
					if (!good[s[j] - 'a'])
						cnt++;

					if (cnt > k)
						break;

					if (current -> next[s[j] - 'a'] != NULL)
						current = current -> next[s[j] - 'a'];
					else
						{
							ans++;
							
							current -> next[s[j] - 'a'] = new Vertex(true);

							current = current -> next[s[j] - 'a']; 
						}	
				}
		}

 	cout << ans;

 	return 0;
}
