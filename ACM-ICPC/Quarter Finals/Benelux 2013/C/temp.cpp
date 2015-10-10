for (int i = 0; s[i]; i++) {
            int c = s[i] - 'a';
            set <int> S;

            for (int j = 0; j < n; j++) {
                if (!can[j]) {
                    continue;
                }

                if (perm[j][c] == -1) {
                    S.insert('\0');
                } else {
                    S.insert(perm[j][c] + 'a');
                }
            }

            if (S.empty() || S.size() > 1u) {
                ans[i] = '?';
            } else{ 
                ans[i] = *S.begin();
            }

            if (av.count(ans[i])) {
                av.erase(ans[i]);
            }
        }