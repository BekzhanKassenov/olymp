#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;

int i1,i2,j1,j2;

struct ftb
{
string name;
int gl;
int rp;
int op;
};

ftb k[2][100];


void poisk1(string nm)
{
for (int i=0; i<n; i++)
{
for (int j=0;j<=1;j++)
if (k[j][i].name==nm) 
{
i1=i;
j1=j;
return;
}
}
return;
}

void poisk2(string nm)
{
for (int i=0; i<n; i++)
{
for (int j=0;j<=1;j++)
if (k[j][i].name==nm) 
{
i2=i;
j2=j;
return;
}
}
return;
}


int main()
{

freopen("football.in","r",stdin);
freopen("football.out","w", stdout);
cin>>n;

for (int j=0;j<=1;j++)
for (int i=0;i<n;i++)
{
cin>>k[j][i].name;
k[j][i].gl=0;
k[j][i].op=0;
k[j][i].rp=0;
}


string a,b,c;

while (! cin.eof())
{
cin>>a;
cin>>b;
if (b=="GOAL!")
    {
        poisk1(a);
        k[j1][i1].gl++;
    }
else
{
while ((! cin.eof()) && (c!="GOAL!"))
    {
        c="";
        cin>>c;
        if (c=="GOAL!")
            {
                poisk1(a);
                poisk2(b);
                k[j2][i2].gl++;
                if (j1==j2)
                    k[j1][i1].rp++; 
                else    
                    k[j1][i1].op++;
            }
        a="";
        a=b;
        b="";
        b=c;
    } 
a="";
b="";
}
}
for (int j=0;j<=1;j++)
for (int i=0;i<n;i++)
cout<<k[j][i].name<<" "<<k[j][i].gl<<" "<<k[i][j].rp<<" "<<k[i][j].op<<"\n";
fclose(stdout);
return 0;
}
