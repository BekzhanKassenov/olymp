#include <iostream>
#include <cstdio>

using namespace std;

/*
    0
   1 2
    3
   4 5
    6
*/

int h, m;
bool state[4][7];
bool turned_on[4][7];
bool turned_off[4][7];

bool digit_state[11][7] = { // 0     1      2      3      4      5       6
							{true,  true,  true,  false, true,  true,  true }, // 0
							{false, false, true,  false, false, true,  false}, // 1
							{true,  false, true,  true,  true,  false, true }, // 2
							{true,  false, true,  true,  false, true,  true }, // 3
							{false, true,  true,  true,  false, true,  false}, // 4
							{true,  true,  false, true,  false, true,  true }, // 5
							{true,  true,  false, true,  true , true,  true }, // 6
							{true,  false, true,  false, false, true,  false}, // 7
							{true,  true,  true,  true,  true,  true,  true }, // 8
							{true,  true,  true,  true,  false, true,  true }, // 9
							{false, false, false, false, false, false, false}  // EMPTY
						  };

bool check() {
 	for (int i = 0; i < 4; i++) {
 		for (int j = 0; j < 7; j++) {
 		 	if (i == 0 && j == 1)
 		 		continue;

 		 	if (!turned_on[i][j] || !turned_off[i][j])
 		 		return false;
 		}
 	}

 	return true;
}

void change_state_of_digit(int position, int ndigit) {
 	for (int i = 0; i < 7; i++) {
 	 	if (!digit_state[ndigit][i]) {
			turned_off[position][i] = true;
 	 	} else {
			turned_on[position][i] = true;
 	 	}

 	 	state[position][i] = digit_state[ndigit][i];
 	}
}

void change_state_of_display(int nh, int nm) {
 	if (nh < 10) {
 	 	change_state_of_digit(0, 10);
 	} else {
 	 	change_state_of_digit(0, nh / 10);
 	}

 	change_state_of_digit(1, nh % 10);
 	change_state_of_digit(2, nm / 10);
 	change_state_of_digit(3, nm % 10);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d:%d", &h, &m);

	int ans = -1;

	while (!check()) {
	 	change_state_of_display(h, m);
	 	ans++;

	 	m++;
	 	if (m == 60) {
	 	 	m = 0;
	 	 	h++;
	 	 	h %= 24;
	 	}
	 	
	 	/*
	 	printf("%02d:%02d\n", h, m);
	 	for (int i = 0; i < 4; i++) {
	 	 	for (int j = 0; j < 7; j++) {
	 	 	 	printf("%d", turned_on[i][j]);
	 	 	}
	 	 	puts("");
	 	}

	 	puts("");
	 	for (int i = 0; i < 4; i++) {
	 	 	for (int j = 0; j < 7; j++) {
	 	 	 	printf("%d", turned_off[i][j]);
	 	 	}
	 	 	puts("");
	 	}

	 	puts("");
	 	puts("");
	 	*/
	}

	printf("%d\n", ans);

	return 0;
}                   	
