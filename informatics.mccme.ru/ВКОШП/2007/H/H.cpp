#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

bool reg = false, nmb = false;

vector <string> keys;

vector <pair <string, int> > ids;

void upcase(string& s)
{
	for (int i = 0; i < s.length(); i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] += ('A' - 'a');

}

bool okay(char c)
{
	if ((c>= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z') ||
		(c >= '0' && c <= '9') ||
		c=='_')
		return true;
	return false;
}

void analyseid(string& id)
{
	if (!id.empty())
		{
			//cout << "ID : " << id << endl;
			bool c = true;
			for (int j = 0; j < id.length(); j++)
				if (!(id[j] >= '0' && id[j] <= '9'))
					{
						c = false;
						break;
					}
		   if (!nmb && (id[0] >= '0' && id[0] <= '9') || c)
			   id.clear();
		   for (int j = 0; j < keys.size(); j++)
			   	if (keys[j] == id)
			   		{
			   			id.clear();
			   			break;
			   		}
			if (!id.empty())
			  	{
			  		for (int j = 0; j < ids.size(); j++)
			  			if (ids[j].first == id)
			  				{
			  					ids[j].second++;
			  					id.clear();
			  					break;
			  				}
			  		if (!id.empty())
			  			{
			  				ids.push_back(make_pair(id, 1));
			  				id.clear();
			  			}
			  	}
			
		}
}
void analyse(string s)
{
   string id;
   for (int i = 0; i < s.length(); i++)
   	{
   		if (okay(s[i]))
   			id += s[i];
   		else
   			{
   				analyseid(id);
   			}
   	}
   if (!id.empty())
   	analyseid(id);
}

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n;
	string s;
	cin >> n >> s;
	if (s == "yes")
		reg = true;
	cin >> s;
	if (s == "yes")
		nmb = true;
	keys.resize(n);
	for (int i = 0; i < n; i++)
		{
			cin >>  keys[i];
			if (!reg)
				upcase(keys[i]);
		}
	while (cin >> s)
		{
			//cout << "string : " << s << endl;
			if (!reg)
				upcase(s);
			analyse(s);
		}
	string ans;
	int mx = 0;
	for (int i = 0; i < ids.size(); i++)
		if (ids[i].second > mx)
			{	
				mx = ids[i].second;
				ans = ids[i].first;
			}
	cout << ans;
	return 0;
}
