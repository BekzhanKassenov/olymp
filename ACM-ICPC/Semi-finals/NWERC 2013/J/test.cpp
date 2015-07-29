#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int tot, mx = 20;
void dfs(){
	tot++;
	if (rand()%2 == 1 && tot > 1){
		cout << 'B';
		return;
	}
	if (tot < mx){
		cout << '(';
		dfs();
		cout << ')';
		cout << '(';
		dfs();
		cout << ')';
	}
}
int main(){
freopen("in", "w", stdout);
	srand(time(0));  
		cout << '(';
		dfs();
		cout << ')';	
	return 0;
}