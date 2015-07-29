#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	int h1, h2, m1, m2, s1, s2;
	char k;

	int d = 0;

	int sk;

	sk = s2 + m2 * 60 + h2 * 60 * 60;

	s1 += sk;

	m1 += s1 / 60;

	s1 %= 60;

	h1 += m1 / 60;

	m1 %= 60;

	d += h1 / 24;

	h1 %= 24;

	stringstream ss;

	if (h1 < 10)
		ss << '0';
	ss << h1 << ':';

	if (m1 < 10)
		ss << '0';
	ss << m1 << ':';

	if (s1 < 10)
		ss << '0';
	ss << s1;

	if (d != 0)
		ss << '+' << d;

	string ans;
	ss >> ans;
	if (d!= 0)
		ans += " days";
	cout << ans;
	return 0;
}
