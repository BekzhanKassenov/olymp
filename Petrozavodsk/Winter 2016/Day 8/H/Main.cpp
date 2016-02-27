#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
#define f first
#define s second
#define ll long long
#define int long long
int inf = 2000000001;

long double eps = 1e-12;

// insert with non-increasing m
vector<ll> M, B;
int ptr;
bool bad(int a,int b,int c) {
  // use deterministic comuputation with long long if sufficient
  return (B[c]-B[a])*1ll*(M[a]-M[b])<(B[b]-B[a])*1ll*(M[a]-M[c]);
}
// insert with non-increasing m
void insert(ll m, ll b) {
  M.push_back(m);
  B.push_back(b);
  while (M.size() >= 3 && bad(M.size()-3, M.size()-2, M.size()-1)) {
    M.erase(M.end()-2);
    B.erase(B.end()-2);
  }
}
long double get(int i, long double u) {
  return M[i]*u + B[i];
}
// query with non-decreasing x
long double query(long double x) {
  ptr=min((int)M.size()-1,ptr);
  while (ptr<M.size()-1 && fabs(get(ptr+1,x) - get(ptr,x)) < eps)
    ptr++;
  return get(ptr,x);
}

ll otv[511111];
pair<ll,ll> rifles[511111];
pair<int,int> r[511111];
pair<long double,pair <pair <int, int> int> > q[511111];

signed main(){
#ifdef Local
    freopen("in","r",stdin);
#endif
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
        cin >> q[i].s.s.f >> q[i].s.s.s;
		q[i].f = q[i].s.s.f / q[i].s.s.s;
		q[i].s.f = i;
	}

	ll lol =inf;
	int m;
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> rifles[i].f >> rifles[i].s;
		lol = min(lol,rifles[i].f);
	}
	sort(rifles,rifles+m);
	for(int i=0;i<m;i++)
		insert(rifles[i].f,rifles[i].s);

	
	sort(q,q+n);
	reverse(q,q+n);
	for(int i=0;i<n;i++)
			otv[q[i].s] = query(q[i].f) * q[i].s.s.s;
	for(int i=0;i<n;i++){
        cout << otv[i] << ' ';
	}

}