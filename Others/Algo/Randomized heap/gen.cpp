#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	freopen("in", "w", stdout);

	srand(time(NULL));

	int n = 1000000 + rand() % 100000;

	printf("%d\n", n);

	for (int i = 0; i < n; i++)
		{
			int c = rand() % 3;

			switch (c)
				{
					case 0:
						printf("+ %d\n", rand() % 10000);
						break;

					case 1:
						printf("-\n");
						break;

				  	case 2:
				  		printf("?\n");
				  		break;
				}
		}

  	return 0;
}
