#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

string create_string(int p) {
	string res;

	for (int i = 0; i < 8; i++) {	
		res += (p % 10 + '0');
		p /= 10;
	}

	reverse(res.begin(), res.end());

	return res;
}

int create_int(const string& s) {
	int res = 0;

	for (int i = 0; i < 8; i++)
		res = (res * 10 + s[i] - '0');

	return res;	
}

int edges[8][3] = {{1, 4, -1}, 
				   {0, 2, 5}, 
				   {1, 3, 6}, 
				   {2, 7, -1}, 
				   {0, 5, -1}, 
				   {4, 1, 6}, 
				   {5, 2, 7}, 
				   {6, 3, -1}
				  };

map <int, int> dist; 

void bfs(const string& start) {
	dist[create_int(start)] = 0;

	queue <int> q;
	q.push(create_int(start));

	while (!q.empty()) {
		int val = q.front();
		string cur = create_string(val);
		q.pop();

		int pos = find(cur.begin(), cur.end(), '0') - cur.begin();

		for (int j = 0; j < 3 && edges[pos][j] != -1; j++) {
		    swap(cur[pos], cur[edges[pos][j]]);
			
			int nval = create_int(cur);

			if (!dist.count(nval) || dist[nval] > dist[val] + 1) {
				dist[nval] = dist[val] + 1;
				q.push(nval);
			}

		    swap(cur[pos], cur[edges[pos][j]]);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, t;
	cin >> s >> t;
	s += t;

	map <char, char> v;
	char cnt = 0;
	v['#'] = 0;
	
	for (int i = 0; i < 8; i++) {
		 if (!v.count(s[i]))
		 	v[s[i]] = ++cnt;
		 
		 s[i] = v[s[i]] + '0';
	}

	bfs(s);
	cin >> s >> t;

	s += t;

	for (int i = 0; i < 8; i++) {
	 	if (!v.count(s[i])) {
	 		cout << -1;
	 		return 0;
	 	}

	 	s[i] = v[s[i]] + '0';
	}

	int val = create_int(s);

	if (!dist.count(val)) {
		cout << -1;
	} else
		cout << dist[val] << endl;

	return 0;
}
