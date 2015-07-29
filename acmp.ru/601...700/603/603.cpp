#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

using namespace std;

char s[4010], temp, q[110];
char buffer[10010];

bool space(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

bool cmpchar(char a, char b) {
    if (isalpha(a) && isalpha(b))
        return toupper(a) == toupper(b);

    return a == b;
}

bool matches(char *check, char *sample) {
	while (*sample) {
	 	while (space(*check))
	 		check++;

	 	while (space(*sample))
	 		sample++;

        if (!*check)
	 		 break;

	 	if (!*sample)	
	 		return false;

	 	while (!space(*sample) && *sample) {
	 	 	if (space(*check))
	 	 		return false;

	 	 	if (!cmpchar(*check, *sample))
	 	 		return false;

	 	 	check++;
	 	 	sample++;
	 	}

	 	if (space(*sample) && !space(*check))
	 		return false;
	}

	return *sample == 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(q);

    char *ptr = s;
    char *bptr = buffer;

    while (!feof(stdin)) {
    	temp = getc(stdin);
    	if (temp != EOF)
    		*ptr++ = temp;
    }

    ptr = s;

    while (*ptr) {
        if (!space(*ptr) && matches(ptr, q))
			*bptr++ = '@';

		*bptr++ = *ptr++;
    }

    puts(buffer);

    return 0;
}
