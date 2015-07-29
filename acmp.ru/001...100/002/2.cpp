#include <iostream>
#include <cstdio> 

using namespace std;

int main() 
{ 
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout); 

int n = 0; 
cin>>n; 
if (n > 0) 
cout<< (n + 1) * n / 2; 
else 
cout<< (n - 1) * n / -2 + 1; 

return 0; 
} 
