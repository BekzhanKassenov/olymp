#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	vector <pair <int, string> > q;
	string s;
	for (;;)
		{	
			cin >> s;
			if (s == "ENDOFINPUT")
				break;
			q.push_back(make_pair(s.length(),s));
		}
	int len = q.size();
	int ans = 0;
	bool t;
   for (int k = 0; k < len; k++)
   	{
   		t = false;
   		for (int j = 0; j < len; j++)  
   			{
   				for (int i = 0; i < len; i++)
   					if ((q[i].first + q[j].first == q[k].first) && (q[i].second + q[j].second == q[k].second))
   						t = true;
   			}
   		ans += int(t);
   	}
   cout << ans;
   return 0;
}
