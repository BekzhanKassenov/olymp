#include <iostream>
#include <cstdio>
#include <set>
#include <string>

using namespace std;

typedef long long ll;

const ll base1 = 31;
const ll MOD1 = (1000 * 1000 * 1000 + 7);

const ll base2 = 37;
const ll MOD2 = (1000 * 1000 * 1000 + 9);

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
  	#endif

  	string s;

  	cin >> s;

  	set <long long> st;

  	int n = s.length();

  	for (int i = 0; i < n; i++)
  		{
  			long long hash1 = 0, hash2 = 0;

  			for (int j = i; j < n; j++)
  				{
  					hash1 = ((hash1 * base1) % MOD1 + s[j]) % MOD1;
  					hash2 = ((hash2 * base2) % MOD2 + s[j]) % MOD2;
  					 
  					st.insert((hash1 << 32) + hash2);
  				}

  		}

  	cout << st.size() << endl;
}
