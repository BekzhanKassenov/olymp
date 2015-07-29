#include <fstream>
main()
{
	std::ifstream i("input.txt");
	std::ofstream o("output.txt");
	int n, f, d=1, c=j=0;
	i>>n;
	while (c<n)
		{
			f=d+c;
			c=d;
			d=f;
			j++;
			if (c==n)
				{
					o<<1<<"\n"<<j;
					
					exit(0);
				}
		}
	o<<0;
}
