#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

typedef struct Node* PNode;

struct Node
{
    bool leaf;

    PNode next[26];

    Node()
        {
            leaf = true;

            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
};

bool has(PNode root, const string& s)
{
    for (size_t i = 0; i < s.size(); i++)
        {
            if (root -> next[s[i] - 'a'] != NULL)
                root = root -> next[s[i] - 'a'];
            else
                return false;   
        }   

    return (root -> leaf);
}

void insert(PNode root, const string& s)
{
    for (size_t i = 0; i < s.size(); i++)
        {
            if (root -> next[s[i] - 'a'] != NULL)
                root = root -> next[s[i] - 'a'];
            else
                {
                    root -> next[s[i] - 'a'] = new Node();
                    root = root -> next[s[i] - 'a'];
                    root -> leaf = false;
                }
        }

    root -> leaf = true;
}

int main()
{
    freopen("in", "r", stdin);
    
    int n;

    cin >> n;

    int k;

    string s;

    PNode root = new Node();

    for (int i = 0; i < n; i++)
        {
            cin >> k >> s;

            if (k == 0)
                {
                    if (has(root, s))
                        puts("YES");
                    else
                        puts("NO"); 
                }
            else
                insert(root, s);    
        }

   return 0;
}
