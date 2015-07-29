#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

long long a, b;

const long long base = 100000000;

struct BigInt
{
	vector <long long> nmb;

	BigInt() {}

	BigInt(long long n)
		{
			while (n)
				{
					nmb.push_back(n % base);
					n /= base;
				}
		}

	BigInt(const vector <long long> &a)
		{
			nmb = a;
		}

	BigInt operator * (long long n)
		{
			vector <long long> tmp;

			long long flag = 0;

			for (int i = 0; i < (int)nmb.size(); i++)
				{
					flag += nmb[i] * n;
					
					tmp.push_back(flag % base);
					
					flag /= base;
				}

			while (flag)
				{
					tmp.push_back(flag % base);
					flag /= base;
				}

			return BigInt(tmp);
		}

	void print()
		{
			int len = nmb.size();

			cout << nmb[len - 1];

			char buf[8];

			for (int i = len - 2; i >= 0; i--)
				{
					sprintf(buf, "%8I64d", nmb[i]);
					for (int i = 0; i < 8; i++)
						if (buf[i] == ' ')
							buf[i] = '0';

					printf("%s", buf);
				}


			printf("\n");
		}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	long long a, b;

	cin >> a >> b;

	long long st = a;

	for (int i = 1; i < 5; i++)
		st *= a;

	BigInt n = BigInt(st);

	for (int i = 1; i < b / 5; i++)
		n = n * st;

	for (int i = 0; i < (b % 5); i++)
		n = n * a;

	n.print();

	return 0;
}
