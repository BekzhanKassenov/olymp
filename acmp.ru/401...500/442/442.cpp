#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool compare(char s[], char t[]) {
    int spos = 0;
    int tpos = 0;

    while (t[tpos] != '\0') {
        if (s[spos] == '\0') {
            return false;
        }

        if (s[spos] != t[tpos]) {
            return false;
        }

        spos++;
        tpos++;
    }

    return true;
}

struct HTML_code {
    static const int MAXN = 5010;

    char s[MAXN];
    size_t len;
    size_t pos;
    size_t size;
    size_t cnt[51];
    bool tag_mode;

    HTML_code() : len(0u),
                  pos(0u),
                  size(10u), 
                  tag_mode(false) {
        
         memset(s, 0, sizeof s);
         memset(cnt, 0, sizeof cnt);
    }

    void add_string(char t[]) {
        strcat(s, t);
        len += strlen(t);
    }

    int parse_size() {
        int result = 0;
        char delta = '\0';

        if (cur_char() == '-' || cur_char() == '+') {
            delta = get_char();
        }

        while (isdigit(cur_char())) {
            result *= 10;
            result += get_char() - '0';
        }
        
        if (delta == '-') {
            result = size - result;
        } else if (delta == '+') {
            result = size + result;
        }

        return result;
    }

    bool has_substring(char t[]) {
        if (!compare(s + pos, t)) {
            return false;
        }

        int tpos = 0;
        while (t[tpos] != '\0') {
            tpos++;
            get_char();
        }

        return true;
    }

    char cur_char() {
        return s[pos];
    }

    char get_char() {
        if (cur_char() == '<') {
            tag_mode = true;
        }
        
        if (!tag_mode && !isspace(cur_char())) {
            cnt[size]++;
        }

        if (cur_char() == '>') {
            tag_mode = false;
        }

        return s[pos++];
    }

    bool finished() {
        return pos >= len;
    }

    void print_freq() {
        for (int i = 0; i < 51; i++) {
            if (cnt[i] != 0) {
                printf("%d %d\n", i, cnt[i]);
            }
        }
    }
};

char font_tag[] = "<font size=\"";
char close_font_tag[] = "</font>";
char temp[HTML_code::MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    HTML_code parser;

    while (gets(temp)) {
        parser.add_string(temp);
    }

    vector <int> font_size;

    while (!parser.finished()) {
        if (parser.has_substring(font_tag)) {
            font_size.push_back(parser.size);
            parser.size = parser.parse_size();
        } else if (parser.has_substring(close_font_tag)) {
            parser.size = font_size.back();
            font_size.pop_back();
        } else {
            parser.get_char();
        }
    }

    parser.print_freq();

    return 0;
}
