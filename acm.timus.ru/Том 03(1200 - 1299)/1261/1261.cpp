#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	int ans = 0;

	vector <int> pows(21);

	pows[0] = 1;

	for (int i = 1; i < 21; i++)
		pows[i] = pows[i - 1] * 3;

	for (int mask = 1; mask < (1 << 21); mask++)
		{
			long long tmp = 0;

			for (int i = 0; i < 21; i++)
				{
					if (mask & (1 << i))
						tmp += pows[i];
				}

			if (tmp > n && tmp < 4294967291ll)
				{
					long long tmp1 = tmp - n;

					bool flag = true;

					int mask2 = 0;

					int cnt = 0;

					while (tmp1)
						{
							if (tmp1 % 3 == 2)
								flag = false;

							mask2 <<= 1;
							mask2 += tmp1 % 3;

							tmp1 /= 3;
						}

					if (flag)
						{
							ans = tmp;
							break;
						}
		      }
	  }

  	if (ans != 0)
  		cout << ans << ' ' << ans - n;
  	else
  		cout << 0;	

  	return 0;
}
	