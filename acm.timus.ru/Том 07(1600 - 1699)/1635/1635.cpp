#include <cstdio>
#include <cstring>

using namespace std;

char s[5000];
int dp[5000][5000], is_pal[5000][5000], prev[5000][5000], len;
bool calced[5000];

bool is_pal() {

}

int calc(int l, int r) {
	
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%s", s + 1);

	len = strlen(s);

	calc(0, len - 1);

	return 0;	
}
