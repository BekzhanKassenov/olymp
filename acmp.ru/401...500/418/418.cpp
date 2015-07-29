#include <iostream>
#include <cstdio>
#include <vector>
#include <list>

using namespace std;

list <int>            lines;
list <int>::iterator  current_line;
list <int>::iterator  temp_line;
int                   result;
char                  c;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    lines.push_back(0);
    current_line = lines.begin();
    
    while ((c = getc(stdin)) && c != EOF) {
        switch (c) {
            case '<':
                if (*current_line == 0) {
                    if (current_line != lines.begin()) {
                        temp_line = current_line;
                        temp_line--;

                        lines.erase(current_line);
                        current_line = temp_line;
                    }
                } else {
                    (*current_line)--;
                }

                break;

            case '^':
                if (current_line != lines.begin()) {
                    current_line--;
                }

                break;

            case '|':
                temp_line = current_line;
                temp_line++;

                if (temp_line != lines.end()) {
                    current_line = temp_line;
                }

                break;

            case '\\':
                current_line++;
                lines.insert(current_line, 0);
                current_line--;
                break;
            
            default:
                (*current_line)++;
                result = max(result, *current_line);
                break;
        }
    }

    printf("%d\n", result);

    return 0;
}
