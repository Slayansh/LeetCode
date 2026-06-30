class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        auto countSegment = [&](const string &s) {
            int n = s.size();
            int ans = 0;

            for (int need = 1; need <= 26; need++) {
                int len = need * k;
                if (len > n) break;

                vector<int> freq(26, 0);
                int distinct = 0;
                int exact = 0;

                for (int i = 0; i < n; i++) {
                    int x = s[i] - 'a';

                    if (freq[x] == k) exact--;
                    if (freq[x] == 0) distinct++;
                    freq[x]++;
                    if (freq[x] == k) exact++;

                    if (i >= len) {
                        int y = s[i - len] - 'a';

                        if (freq[y] == k) exact--;
                        if (freq[y] == 1) distinct--;
                        freq[y]--;
                        if (freq[y] == k) exact++;
                    }

                    if (i >= len - 1) {
                        if (distinct == need && exact == need)
                            ans++;
                    }
                }
            }

            return ans;
        };

        int ans = 0;
        int start = 0;
        int n = word.size();

        for (int i = 1; i < n; i++) {
            if (abs(word[i] - word[i - 1]) > 2) {
                ans += countSegment(word.substr(start, i - start));
                start = i;
            }
        }

        ans += countSegment(word.substr(start));

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna