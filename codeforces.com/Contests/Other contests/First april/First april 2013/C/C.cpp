#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int tux;

	cin >> tux;

	int foo = 0, bar = 0, baz = 0, quz = 0;

	for (int i = 0; i < tux; i++) {
		int pur;

		cin >> pur;
		foo += pur;
		bar++;

		if (max(foo * quz, bar * baz) == foo * quz) {
			baz = foo;
			quz = bar;
		}
	}

	printf("%.10lf", (baz + .0) / (quz + .0));

	return 0;
}
