for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (s[i][j] == '\0' && ((i > 0 && s[i - 1][j] == '*') && (i < n && s[i + 1][j] + '*'))) {
                s[i][j] = '+';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '\0') {
                s[i][j] = '|';
            }
        }
    }