/****************************************
**        Solution by NU 02:           **
**		  Bekzhan Kassenov             **
**		  Anuar Serikov                **
**		  Nursultan Zarlyk             **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

struct sequencer {
	int size;
	int id[10], status[10];
	bool disc[10], on[10], need[10], available;
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int m, nt, cur, n, argh[100];
	int num1, num2;
	string s, g;

	cin >> nt; 

	while (nt--) {
		int last = 0;
	    cin >> s >> g;
		n = s.length();
		cur = 0;
		m = g.length();
		vector <sequencer > v (10);
		v.resize (0);
		v[cur].size = 0;

		for (int i = 0; i < n; i++) {
			if (isdigit (s[i])) {
				last = max(last, s[i] - '0');
				argh[s[i] - '0'] = cur;
				v[cur].id[v[cur].size] = s[i] - '0';
				v[cur].on[v[cur].size] = false;
				v[cur].status[v[cur].size] = false; 
				v[cur].disc[v[cur].size] = false;
				v[cur].need[v[cur].size++] = true;
				v[cur].available = false;
			}
			else if (s[i] == '#') {
				v[cur].need[v[cur].size - 1] = false;
			}
			else if (s[i] == '-') {
				cur++;         				
				v[cur].size = 0;
			}   		
		}
		cur++;
		v[0].available = 1;

        for (int i = 0; i < m; i++) {
// -------------------------------------------------------------------------------------------------------------
        	if (isdigit (g[i])) {
        		num1 = g[i] - '0';
        		
        		if (i + 1 < m && isdigit (g[i + 1])) num2 = g[i + 1] - '0';
        		else num2 = num1;
        		
//        		cout << "New numbers are: " << num1 << " " << num2 << endl;

        		if (!v[argh[num1]].available || !v[argh[num2]].available || argh[num1] != argh[num2]) {
        			cout << "INCORRECT\n";
        			goto skip;
        		}
        		if (num1 != num2) { i++; continue; }
        		bool ok1 = false, ok2 = false;
        		for (int j = 0; j < cur; j++)
        			for (int k = 0; k < v[j].size; k++)
        			{
        				if (v[j].id[k] == num1) ok1 = true;
        				if (v[j].id[k] == num2) ok2 = true;
        			}
        		if (!ok1 || !ok2) {
        			cout << "INCORRECT\n";
        			goto skip;
        		}
        	}
// -------------------------------------------------------------------------------------------------------------
        	else if (g[i] == '+') {
//                cout << "Trying to connect # " << num1 << " and " << num2 << "..." << endl;
        		for (int j = 0; j < v[argh[num1]].size; j++) {
        			int i1 = argh[num1], i2 = argh[num2];
        			if (v[argh[num1]].id[j] == num1 && (v[i1].disc[j] == true || v[argh[num1]].on[j] == true || v[argh[num1]].need[j] == false)) {
        				cout << "INCORRECT\n";
        				goto skip;
        			}
        			if (v[argh[num2]].id[j] == num2 && (v[i2].disc[j] == true || v[argh[num2]].on[j] == true || v[argh[num2]].need[j] == false)) {
        				cout << "INCORRECT\n";
        				goto skip;
        			}
        		}


        		for (int j = 0; j < v[argh[num1]].size; j++) {
        			if (v[argh[num1]].id[j] == num1) {
        				v[argh[num1]].on[j] = true;
//        				cout << num1 << " is successfully connected!\n";
        			}
        			if (v[argh[num2]].id[j] == num2) {
        				v[argh[num2]].on[j] = true;
//        				cout << num2 << " is successfully connected!\n";
        			}
        		}

        	}
// -------------------------------------------------------------------------------------------------------------
            else if (g[i] == '-') {
            	int i1 = argh[num1];
            	for (int j = 0; j < v[i1].size; j++)
            		if (v[i1].id[j] == num1) {
 //           			cout << "Trying to disconnect #" << num1 << "..\n";
            			if (v[i1].need[j] == true && v[i1].on[j] == false) {
//            				cout << "ERROR! need = " << v[i1].need[j] << ", on = " << v[i1].on[j] << endl;
                            incorrect:;
            				cout << "INCORRECT\n";
            				goto skip;
            			}
            			for (int k = 1; k < num1; k++) {
            				int idd = argh[k];
            				for (int l = 0; l < v[idd].size; l++)
            				{
            					if (v[idd].id[l] == k) {
            						if (v[idd].disc[l] == false) {goto incorrect;}
            					}
            				}
            			}
            			v[i1].disc[j] = true;
//            			cout << num1 << " is successfully disconnected!\n";
            		}
            
                bool flag = true;    /*
                cout << "statistic: \n";
				for (int j = 0; j < v[i1].size; j++) 
					cout << v[i1].id[j] << " :  " << v[i1].need[j] << " " << v[i1].on[j] << endl;
            	cout << "end of statistic\n";
            	                       */
            	for (int j = 0; j < v[i1].size; j++) {
            		if (v[i1].disc[j] == false) {
            			flag = false;
            			break;
            		}
            	}
            	if (flag) {
            		v[i1].available = false;
            		v[i1 + 1].available = true;
            	}
            }
//            cout << endl << endl;
// -------------------------------------------------------------------------------------------------------------
        }

           			for (int k = 1; k < last; k++) {
            				int idd = argh[k];
            				for (int l = 0; l < v[idd].size; l++)
            				{
            					if (v[idd].id[l] == k) {
            						if (v[idd].disc[l] == false) {cout << "INCORRECT\n"; goto skip;}
            					}
            				}
            			}
 
        cout << "CORRECT\n";

        skip:;
	}

	return 0;
}
